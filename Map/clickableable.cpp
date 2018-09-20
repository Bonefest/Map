#include <clickablelabel.h>

ClickableLabel::ClickableLabel(const QString &text, QWidget *parent):QLabel(text,parent) {}
ClickableLabel::~ClickableLabel() { }

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    emit clicked();
}
