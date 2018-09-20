#ifndef DIALOGMULTIPLY
#define DIALOGMULTIPLY

#include <QFrame>
#include <vector>
#include <QString>
#include <QLabel>
#include <QLineEdit>
#include <QDialogButtonBox>

class MultiplyDialog : public QFrame {
private:
    QLabel* title;
    QLabel* inputLabels;
    QLineEdit* editLines;
    QDialogButtonBox* buttons;

    double vspace;
    double hspace;

public:

    //Дополнительно принимает вектор строк - названий соответствующих названий для полей ввода
    //Генерирует во фрейме последовательно множество полей ввода
    MultiplyDialog(QWidget* parent,std::vector<QString>,const QString& title = "Enter data",double verticalSpace = 10.0,double horizontalSpace=20.0);
    ~MultiplyDialog();

    void setTitle(const QString& title);
};

#endif // DIALOGMULTIPLY

