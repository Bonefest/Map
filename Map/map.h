#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLayout>

#include <string>
#include <fstream>

#include <clickablelabel.h>
#include <placeholder.h>

namespace Ui {
class Map;
}

class Map : public QMainWindow
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = 0);
    ~Map();

private slots:
    void selectGcp();
    void selectMap();
    void addImage();
    void loadImage(QListWidgetItem* item);
    void clickImage();
    void clickPlaceholder(const Placeholder*);

private:
    //USER INTERFACE
    Ui::Map *ui;

    ClickableLabel* image;  //Главное изображение,на котором выводится карта

    QMenu* gcpOption;       //Опция загрузки файла точок связки локальных и глобальных координат
    QMenu* addImageOption;  //Опция добавления изображения к текущему списку
    QMenu* loadMapOption;   //Опция загружения списка изображений , которые представляют карту

    //DATA
    QList<Placeholder*> placeholders;   //Хранит точки,которые были указаны на карте
    std::string gcpFileName;            //Хранит имя выбранного gcp файла
    std::string mapFileName;            //Хранит имя выбранного map файла

    //FUNCTIONS
    void loadGCPFile(QString filePath);
    void loadMap(QString filePath);
    void loadPlaceholders(const QString& image);
    void addGcpElement(const Placeholder* placeholder,const QString& fname);    //Добавить точку в файл

    inline void showBadFileMessage(QWidget* parent) { QMessageBox::warning(parent,"Incorrect file","Incorrect file.Please try again."); }  //Выводит сообщения неправильного выбора файла
};

#endif // MAP_H
