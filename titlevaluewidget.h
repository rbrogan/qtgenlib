#ifndef TITLEVALUEWIDGET_H
#define TITLEVALUEWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QBoxLayout>

class TitleValueWidget : public QWidget
{
     Q_OBJECT
public:
     explicit TitleValueWidget(QString title = "", QString initialValue = "", Qt::Orientation orientation = Qt::Horizontal, QWidget *parent = 0);
     QLabel *titleLabel;
     QLabel *valueLabel;
     QBoxLayout *layout;
     QString currentValue;
     QString previousValue;
    
signals:
     void changed(QString currentValue, QString previousValue);
    
public slots:
     void update(QString newValue);
    
};

#endif // TITLEVALUEWIDGET_H
