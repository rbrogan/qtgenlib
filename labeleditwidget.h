#ifndef LABELEDITWIDGET_H
#define LABELEDITWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QBoxLayout>

class LabelEditWidget : public QWidget
{
     Q_OBJECT
public:
     explicit LabelEditWidget(QString title, QString initialValue = "", Qt::Orientation orientation = Qt::Horizontal, QWidget *parent = 0);
     QLabel *titleLabel;
     QLineEdit *valueEdit;
     QBoxLayout *layout;
     QString currentValue;
     QString previousValue;
    
signals:
     void changed(QString currentValue, QString previousValue);
    
public slots:
     void update(QString newValue);
    
};

#endif // LABELEDITWIDGET_H
