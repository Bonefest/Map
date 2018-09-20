#include <dialogmultiply.h>
#include <QString>
#include <memory>

MultiplyDialog::MultiplyDialog(QWidget *parent, std::vector<QString> labels,const QString& tit,double verticalSpace,double horizontalSpace):QFrame(parent),vspace(verticalSpace),hspace(horizontalSpace) {
    setGeometry(geometry().x(),geometry().y(),200,168);

    title = new QLabel(this);
    setTitle(tit);

    inputLabels = new QLabel[labels.size()];
    for(unsigned int s = 0;s<labels.size();++s) {
        inputLabels[s].setParent(this);
        inputLabels[s].setText(labels[s]);
        inputLabels[s].setGeometry(0,title->pos().y()+vspace*(s+1),30,30);
    }
    buttons = new QDialogButtonBox(this);
    buttons->setStandardButtons(QDialogButtonBox::Ok);
    buttons->setStandardButtons(QDialogButtonBox::Cancel);
}

MultiplyDialog::~MultiplyDialog() { delete [] inputLabels; delete [] editLines;delete title; }

void MultiplyDialog::setTitle(const QString& t) {
    title->setText(t);
    title->setAlignment(Qt::AlignCenter);
    title->setGeometry(title->geometry().x(),title->geometry().y(),this->geometry().width(),40);
}
