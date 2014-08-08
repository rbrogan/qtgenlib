#include "todchime.h"

TodChime::TodChime(QString timeOfDayString, int checkIntervalMsec, int chimeWidthSec, QObject *parent) :
    QTimer(parent)
{
     this->checkIntervalMsec = checkIntervalMsec;
     this->chimeWidthSec = chimeWidthSec;
     this->targetTimeOfDay = QTime::fromString(timeOfDayString, "hh:mm:ss");

     setInterval(this->checkIntervalMsec);
     setSingleShot(false);

     connect(this, SIGNAL(timeout()), this, SLOT(timeoutProc()));
}

void TodChime::setTargetTimeOfDay(QString timeOfDayString)
{
     stop();
     targetTimeOfDay = QTime::fromString(timeOfDayString, "hh:mm:ss");
     start();
}

void TodChime::timeoutProc()
{
     if (QTime::currentTime().addSecs(chimeWidthSec) >= targetTimeOfDay) {
          emit chime();
     }
}

void TodChime::trigger()
{
     emit chime();
}




