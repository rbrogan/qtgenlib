#include "labeleditwidget.h"

LabelEditWidget::LabelEditWidget(QString title, QString initialValue, Qt::Orientation orientation, QWidget *parent)
     : QWidget(parent)
{
     if (orientation == Qt::Horizontal) {
          layout = new QHBoxLayout;
     } else {
          layout = new QVBoxLayout;
     }
     setLayout(layout);

     titleLabel = new QLabel(title);
     valueEdit = new QLineEdit(initialValue);

     layout->addWidget(titleLabel, (orientation == Qt::Horizontal) ? Qt::AlignRight : Qt::AlignBottom);
     layout->addWidget(valueEdit, (orientation == Qt::Horizontal) ? Qt::AlignLeft : Qt::AlignTop);
     layout->addStretch(1);
     layout->setStretchFactor(titleLabel, 0);
     previousValue = "";
     currentValue = initialValue;

     connect(valueEdit, &QLineEdit::returnPressed,
             [=]()
     {
          this->update(this->valueEdit->text());
     });
}

void LabelEditWidget::update(QString newValue)
{
     previousValue = currentValue;
     currentValue = newValue;
     valueEdit->setText(currentValue);
     emit changed(currentValue, previousValue);
}
