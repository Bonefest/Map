#include <QMessageBox>
#include <QFileDialog>
#include <QGraphicsView>
#include <QPushButton>
#include <QInputDialog>
#include <QPixmap>

#include <sstream>
#include <string>
#include <cfloat>
#include <iostream>

#include "map.h"
#include "ui_map.h"
#include "placeholder.h"

Map::Map(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Map),
    gcpFileName("")
{
    ui->setupUi(this);

    image = new ClickableLabel("",this);

    image->setScaledContents(true);
    image->setGeometry(QRect(140,70,1121,911));
    image->setStyleSheet(QString("border-style:solid;border-width:1px;background-color:rgbargb(42, 43, 37);"));

    gcpOption = new QMenu("Select GCP file");
    addImageOption = new QMenu("Add image");
    loadMapOption = new QMenu("Load map");

    connect(gcpOption,SIGNAL(aboutToHide()),this,SLOT(selectGcp()),Qt::UniqueConnection);
    connect(loadMapOption,SIGNAL(aboutToHide()),this,SLOT(selectMap()),Qt::UniqueConnection);
    connect(addImageOption,SIGNAL(aboutToHide()),this,SLOT(addImage()));
    connect(ui->listWidget,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(loadImage(QListWidgetItem*)));
    connect(image,SIGNAL(clicked()),this,SLOT(clickImage()));

    ui->menuBar->addMenu(gcpOption);
    ui->menuBar->addMenu(loadMapOption);
    ui->menuBar->addMenu(addImageOption);

}

//=============================[ADD FUNCTIONS]============================

void Map::addImage() {
    //Добавляет выбранное изображение,в заранее выбранный map файл
    if(mapFileName != "") {
        QString newMapFile = QFileDialog::getOpenFileName(this,"Add new image","",tr("Image Files (*.jpg)"));
        std::ofstream foutput(mapFileName,std::ios_base::out|std::ios_base::app);
        if(foutput.is_open()) {
            foutput << std::endl << newMapFile.toStdString();

            foutput.close();
        } else showBadFileMessage(this);
    } else QMessageBox::warning(this,"Map file not found","Map file not found.Please use the 'Load map option'");

}

void Map::addGcpElement(const Placeholder *placeholder, const QString &fname) {
    //Добавляет метку в выбранный gcp файл
    if(gcpFileName!="") {
        std::ofstream out(gcpFileName,std::ios_base::out|std::ios_base::app);
        out << placeholder->getLongtitude() << " " << placeholder->getLatitude() << " " << placeholder->getHeight() << " "
            << placeholder->getPixel().x() << " " << placeholder->getPixel().y() << " " << fname.toLocal8Bit().data() << std::endl;
    }
}


//============================[SELECT FUNCTIONS]===========================

void Map::selectGcp() {
    QString gcpName = QFileDialog::getOpenFileName(this,tr("Choosing gcp file"),"",tr("Image Files (*.txt)"));
    loadGCPFile(gcpName);
}

void Map::selectMap() {
    //Слот для верхнего меню выбора карты
    QString mapName = QFileDialog::getOpenFileName(this,tr("Choosing map file"),"",tr("Image Files (*.txt)"));
    mapFileName = mapName.toStdString();
    loadMap(mapName);
}

//===========================[CLICK FUNCTIONS]============================

void Map::clickImage() {
    //Вызывает событие при нажатии на карту
    if(gcpFileName=="") {
        QMessageBox::warning(this,"Gcp","Please choose a gcp-text file!");
        return;
    }

    if(ui->listWidget->count() > 0 && image->pixmap() != nullptr) {
        std::stringstream sstream;
        QPoint p = image->mapFromGlobal(QCursor::pos());
        sstream << "Image X: " << p.x() << ", Y: " << p.y();
        ui->positionMouse->setText(sstream.str().c_str());

        QPoint cursor = QCursor::pos();

        bool status = false;
        double latitude = QInputDialog::getDouble(this,"Latitude","Enter latitude for this point",0,DBL_MIN,DBL_MAX,6,&status);
        if(!status) return;

        double longtitude = QInputDialog::getDouble(this,"Longtitude","Enter longtitude for this point",0,DBL_MIN,DBL_MAX,6,&status);
        if(!status) return;

        double height = QInputDialog::getDouble(this,"Height","Enter height for this point",0,DBL_MIN,DBL_MAX,6,&status);
        if(!status) return;

        placeholders.append(new Placeholder(latitude,longtitude,height,p.x(),p.y()));
        placeholders.last()->setPixmap(QPixmap(QDir::currentPath()+"/placeholder.png"));
        placeholders.last()->setGeometry(cursor.x(),cursor.y()-64,32,32);

        connect(placeholders.last(),SIGNAL(clicked(const Placeholder*)),this,SLOT(clickPlaceholder(const Placeholder*)));

        this->layout()->addWidget(placeholders.last());
        addGcpElement(placeholders.last(),ui->listWidget->currentItem()->text());

    }
}

void Map::clickPlaceholder(const Placeholder* placeholder) {
    //Выводит значение метки
    std::stringstream stream;
    stream << "[Latitude]  : " << placeholder->getLatitude() << std::endl;
    stream << "[Longtitude]: " << placeholder->getLongtitude() << std::endl;
    stream << "[Height]    : " << placeholder->getHeight() << std::endl;
    stream << "[Screen px] : " << placeholder->getPixel().x() << std::endl;
    stream << "[Screen py] : " << placeholder->getPixel().y() << std::endl;
    QMessageBox::information(this,"Info",stream.str().c_str());
}

//============================[LOAD FUNCTIONS]============================

void Map::loadGCPFile(QString filePath) {
    //Получает путь к GCP файлу

    if(filePath.size() > 0) {
        std::ifstream finput;

        finput.open(filePath.toLocal8Bit().data());
        if(finput.is_open()) {
            gcpFileName = filePath.toLocal8Bit().data();

            ui->gcpStatusLabel->setText(filePath);
            finput.close();\
        } else showBadFileMessage(this);
    }
}

void Map::loadImage(QListWidgetItem *item) {
    //Загружает изображение с выбранного элемента
    for(auto beg = placeholders.begin();beg!=placeholders.end();beg++)
        delete *beg;
    placeholders.clear();

    QPixmap pixmap(QDir::currentPath()+item->text());
    if(!pixmap) pixmap.load(item->text());

    image->setPixmap(pixmap);
    loadPlaceholders(ui->listWidget->currentItem()->text());
}

void Map::loadMap(QString filePath) {
    //Читает текстовый файл, получая список загружаемых изображений, которые представляют карту
    if(filePath.size() > 0) {
        std::ifstream finput;
        finput.open(filePath.toLocal8Bit().data());

        if(finput.is_open()) {

            ui->listWidget->clear();    //Очищает список меток

            std::string imageLine;
            while(std::getline(finput,imageLine)) {
                QListWidgetItem* item = new QListWidgetItem(imageLine.c_str());
                ui->listWidget->addItem(item);

            }


            finput.close();
        } else showBadFileMessage(this);
    }

}

void Map::loadPlaceholders(const QString& imgName) {
    //Если gcp файл выбран , загружает все метки, которые были сохранены в изображении , имя которого передается в аргументе

    if(image->pixmap() && ui->listWidget->currentItem()->text() != "" && gcpFileName != "") {

        double lon,lat,hei,px,py;
        std::string name;
        std::string temp;

        std::ifstream fin(gcpFileName);
        while(fin) {
            fin >> temp;lon = QString(temp.c_str()).toDouble();
            fin >> temp;lat = QString(temp.c_str()).toDouble();
            fin >> temp;hei = QString(temp.c_str()).toDouble();
            fin >> temp;px = QString(temp.c_str()).toDouble();
            fin >> temp;py = QString(temp.c_str()).toDouble();

            if(!fin) break;
            fin >> name;

            if(name == imgName.toLocal8Bit().data()) {
                placeholders.append(new Placeholder(lat,lon,hei,px,py,"",this));
                placeholders.last()->setPixmap(QPixmap(QDir::currentPath()+"/placeholder2.png"));
                placeholders.last()->setGeometry(QRect(image->mapToGlobal(QPoint(px,py-64)),QSize(32,32)));

                connect(placeholders.last(),SIGNAL(clicked(const Placeholder*)),this,SLOT(clickPlaceholder(const Placeholder*)));
                this->layout()->addWidget(placeholders.last());
            }
        }


    }


}

//============================[OTHER FUNCTIONS]============================
Map::~Map()
{
    delete ui;
}

