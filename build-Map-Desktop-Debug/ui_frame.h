/********************************************************************************
** Form generated from reading UI file 'frame.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRAME_H
#define UI_FRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Frame
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *longtitudeLine;
    QLabel *longtitude;
    QLabel *latitude;
    QLineEdit *latitudeLine;
    QLabel *height;
    QLineEdit *heighLine;
    QLabel *title;
    QPushButton *pushButton;

    void setupUi(QFrame *Frame)
    {
        if (Frame->objectName().isEmpty())
            Frame->setObjectName(QStringLiteral("Frame"));
        Frame->resize(200, 166);
        Frame->setStyleSheet(QLatin1String("background-color:rgb(40, 41, 35);\n"
"color:rgb(241, 141, 27);"));
        Frame->setFrameShape(QFrame::StyledPanel);
        Frame->setFrameShadow(QFrame::Raised);
        buttonBox = new QDialogButtonBox(Frame);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 130, 166, 22));
        buttonBox->setStyleSheet(QStringLiteral("color:white;"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        longtitudeLine = new QLineEdit(Frame);
        longtitudeLine->setObjectName(QStringLiteral("longtitudeLine"));
        longtitudeLine->setGeometry(QRect(80, 30, 113, 22));
        longtitude = new QLabel(Frame);
        longtitude->setObjectName(QStringLiteral("longtitude"));
        longtitude->setGeometry(QRect(10, 30, 59, 16));
        latitude = new QLabel(Frame);
        latitude->setObjectName(QStringLiteral("latitude"));
        latitude->setGeometry(QRect(10, 60, 59, 16));
        latitudeLine = new QLineEdit(Frame);
        latitudeLine->setObjectName(QStringLiteral("latitudeLine"));
        latitudeLine->setGeometry(QRect(80, 60, 113, 22));
        height = new QLabel(Frame);
        height->setObjectName(QStringLiteral("height"));
        height->setGeometry(QRect(10, 90, 59, 16));
        heighLine = new QLineEdit(Frame);
        heighLine->setObjectName(QStringLiteral("heighLine"));
        heighLine->setGeometry(QRect(80, 90, 113, 22));
        title = new QLabel(Frame);
        title->setObjectName(QStringLiteral("title"));
        title->setGeometry(QRect(60, 4, 81, 26));
        QFont font;
        font.setPointSize(12);
        title->setFont(font);
        pushButton = new QPushButton(Frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 60, 80, 22));

        retranslateUi(Frame);

        QMetaObject::connectSlotsByName(Frame);
    } // setupUi

    void retranslateUi(QFrame *Frame)
    {
        Frame->setWindowTitle(QApplication::translate("Frame", "Frame", 0));
        longtitude->setText(QApplication::translate("Frame", "Longitude", 0));
        latitude->setText(QApplication::translate("Frame", "Latitude", 0));
        height->setText(QApplication::translate("Frame", "Height", 0));
        title->setText(QApplication::translate("Frame", "Point Info", 0));
        pushButton->setText(QApplication::translate("Frame", "PushButton", 0));
    } // retranslateUi

};

namespace Ui {
    class Frame: public Ui_Frame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRAME_H
