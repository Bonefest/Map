#include <placeholder.h>

Placeholder::Placeholder(double lat, double lon, double hei, double px, double py, const QString &text, QWidget *parent):ClickableLabel(text,parent),latitude(lat),longtitude(lon),height(hei),pixelx(px),pixely(py) {}


Placeholder::~Placeholder() { }

void Placeholder::mousePressEvent(QMouseEvent *event) {
    ClickableLabel::mousePressEvent(event);
    emit clicked(this);
}
