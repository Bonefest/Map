/********************************************************************************
** Form generated from reading UI file 'map.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAP_H
#define UI_MAP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Map
{
public:
    QWidget *centralWidget;
    QListWidget *listWidget;
    QLabel *gcpStatusLabel;
    QLabel *positionMouse;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Map)
    {
        if (Map->objectName().isEmpty())
            Map->setObjectName(QStringLiteral("Map"));
        Map->resize(1280, 1024);
        centralWidget = new QWidget(Map);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QLatin1String("background-color:rgb(40, 41, 35);\n"
"Placeholder {\n"
"	background-color:rgb(255, 0, 0);\n"
"}\n"
"\n"
"Placeholder:hover {\n"
"	background-color:rgb(255, 255, 0);\n"
"}"));
        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 121, 931));
        listWidget->setContextMenuPolicy(Qt::NoContextMenu);
        listWidget->setStyleSheet(QLatin1String("background-color:rgbargb(40, 41, 35);\n"
"color:rgb(213, 130, 36);\n"
"\n"
"QListView::item {\n"
"	color:black;\n"
"	border: 1px;\n"
"};"));
        listWidget->setFrameShape(QFrame::StyledPanel);
        listWidget->setViewMode(QListView::ListMode);
        gcpStatusLabel = new QLabel(centralWidget);
        gcpStatusLabel->setObjectName(QStringLiteral("gcpStatusLabel"));
        gcpStatusLabel->setGeometry(QRect(138, -1, 1141, 31));
        QFont font;
        font.setFamily(QStringLiteral("Monospace"));
        font.setPointSize(16);
        gcpStatusLabel->setFont(font);
        gcpStatusLabel->setStyleSheet(QStringLiteral("color:rgb(241, 141, 27)"));
        gcpStatusLabel->setTextFormat(Qt::RichText);
        gcpStatusLabel->setAlignment(Qt::AlignCenter);
        gcpStatusLabel->setWordWrap(false);
        positionMouse = new QLabel(centralWidget);
        positionMouse->setObjectName(QStringLiteral("positionMouse"));
        positionMouse->setGeometry(QRect(0, 960, 151, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("Monospace"));
        font1.setPointSize(8);
        positionMouse->setFont(font1);
        positionMouse->setStyleSheet(QStringLiteral("color:rgb(255, 255, 255)"));
        positionMouse->setTextFormat(Qt::RichText);
        positionMouse->setAlignment(Qt::AlignCenter);
        positionMouse->setWordWrap(false);
        Map->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Map);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 19));
        Map->setMenuBar(menuBar);
        statusBar = new QStatusBar(Map);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Map->setStatusBar(statusBar);

        retranslateUi(Map);

        QMetaObject::connectSlotsByName(Map);
    } // setupUi

    void retranslateUi(QMainWindow *Map)
    {
        Map->setWindowTitle(QApplication::translate("Map", "Map", 0));
        gcpStatusLabel->setText(QApplication::translate("Map", "Choose a GCP file", 0));
        positionMouse->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Map: public Ui_Map {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAP_H
