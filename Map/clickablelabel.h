#ifndef CLICKABLELABEL
#define CLICKABLELABEL
#include <QLabel>
#include <QWidget>

class ClickableLabel : public QLabel {
/*
 * Класс , который наследует QLabel , дополнительно переопределяя событие нажатия.
 */
    Q_OBJECT
public:
    explicit ClickableLabel(const QString& text="",QWidget* parent=0);
    virtual ~ClickableLabel();

signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
};

#endif // CLICKABLELABEL

