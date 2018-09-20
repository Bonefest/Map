#ifndef PLACEHOLDER
#define PLACEHOLDER

#include <clickablelabel.h>
#include <QString>
#include <QWidget>
#include <QPoint>

class Placeholder : public ClickableLabel {
/*
 * Класс , который наследует пользовательский класс ClickableLabel.
 * Роль : метка (или указатель) на карте.
 * По сути : Добавляет к QLabel событие нажатия клавиши, а также новые данные.
 *
 * Данные, которые представляют :
 * а)географическую позицию : широта, долгота и высота.
 * б)позицию относительно изображения карты : позиция Х и У от верхнего левого угла.
 */
    Q_OBJECT
private:
    double latitude;
    double longtitude;
    double height;
    double pixelx;
    double pixely;
signals:
    void clicked(const Placeholder* placeholder);
public:
    Placeholder(double latitude,double longtitude,double height,double pixelx,double pixely,const QString& text="",QWidget* parent=0);
    ~Placeholder();

    double getLatitude() const { return latitude; }
    double getLongtitude() const { return longtitude; }
    double getHeight() const { return height; }
    QPoint getPixel() const { return QPoint(pixelx,pixely); }
protected:
    void mousePressEvent(QMouseEvent* event);

};


#endif // PLACEHOLDER

