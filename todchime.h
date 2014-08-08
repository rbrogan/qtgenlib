#ifndef TODCHIME_H
#define TODCHIME_H

#include <QTimer>
#include <QTime>

class TodChime : public QTimer
{
     Q_OBJECT
public:
     explicit TodChime(QString timeOfDayString, int checkIntervalMsec = 1000, int chimeWidthSec = 5, QObject *parent = 0);

     QTime targetTimeOfDay;
     int checkIntervalMsec;
     int chimeWidthSec;
    
signals:
     void chime();
    
public slots:
     void setTargetTimeOfDay(QString timeOfDayString);
     void timeoutProc();
     void trigger();
    
};

#endif // TODCHIME_H
