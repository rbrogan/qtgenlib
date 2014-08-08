#ifndef QSTRINGLISTINPUTDIALOG_H
#define QSTRINGLISTINPUTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QStringList>

class QStringListInputDialog : public QDialog
{
     Q_OBJECT
public:
     explicit QStringListInputDialog(QString titleString, QWidget *parent = 0);
    
     QTextEdit *text;
     QStringList items;
signals:
    
public slots:
     void splitAndAccept();
    
};

extern QStringList getQStringListFromUser(QString dialogTitle, QWidget *parent = 0);

#endif // QSTRINGLISTINPUTDIALOG_H
