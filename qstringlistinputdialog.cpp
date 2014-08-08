#include "qstringlistinputdialog.h"
#include <QVBoxLayout>
#include <QDialogButtonBox>
#include <QPushButton>

QStringListInputDialog::QStringListInputDialog(QString titleString, QWidget *parent) :
    QDialog(parent)
{
     setWindowTitle(titleString);

     auto layout = new QVBoxLayout;
     setLayout(layout);
     text = new QTextEdit;

     auto buttonBox = new QDialogButtonBox(Qt::Horizontal);
     auto okButton = new QPushButton(tr("&Ok"));
     auto cancelButton = new QPushButton(tr("&Cancel"));
     buttonBox->addButton(okButton, QDialogButtonBox::AcceptRole);
     buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

     connect(okButton, SIGNAL(clicked()), this, SLOT(splitAndAccept()));
     connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

     layout->addWidget(text);
     layout->addWidget(buttonBox);
}

void QStringListInputDialog::splitAndAccept()
{
     QString contentsString = text->toPlainText();
     items = contentsString.split('\n');
     if (items[items.count() - 1].isEmpty()) {
          items.removeLast();
     }

     accept();
}

QStringList getQStringListFromUser(QString dialogTitle, QWidget *parent)
{
     QStringList retObj;
     QStringListInputDialog dialog(dialogTitle, parent);
     if (dialog.exec()) {
          retObj = dialog.items;
     } else {
          retObj = QStringList();
     }

     return retObj;
}


