
#ifndef THREADWORKER_H
#define THREADWORKER_H


#include <QObject>
#include <QThread>
#include <QDebug>

class ThreadWorker: public QObject
{
    Q_OBJECT
public:
    ThreadWorker();

    //function that will be doing some work
    void workFunction();

signals:
    //emits a signal when it is finished
    void finished();
};

#endif // THREADWORKER_H
