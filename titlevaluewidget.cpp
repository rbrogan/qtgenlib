#include "titlevaluewidget.h"

TitleValueWidget::TitleValueWidget(QString title, QString initialValue, Qt::Orientation orientation, QWidget *parent) :
    QWidget(parent)
{
     titleLabel = new QLabel(title);
     valueLabel = new QLabel(initialValue);

     if (orientation == Qt::Horizontal) {
          layout = new QHBoxLayout;
     } else {
          layout = new QVBoxLayout;
     }

     layout->addWidget(titleLabel, (orientation == Qt::Horizontal) ? Qt::AlignRight : Qt::AlignBottom);
     layout->addWidget(valueLabel, (orientation == Qt::Horizontal) ? Qt::AlignLeft : Qt::AlignTop);

     setLayout(layout);

     previousValue = "";
     currentValue = initialValue;
}

void TitleValueWidget::update(QString newValue)
{
     previousValue = currentValue;
     currentValue = newValue;
     valueLabel->setText(newValue);
     emit changed(currentValue, previousValue);
}
