
#include "threadworker.h"

ThreadWorker::ThreadWorker()
{
    //nothing here
}

void ThreadWorker::workFunction()
{
    qDebug() << "The name of the current thread is: " << QThread::currentThread()->objectName();

    for(int i = 0; i < 10; i++)
    {
        qDebug() << "The thread will now sleep for 500ms";
        QThread::currentThread()->msleep(500);
        qDebug() << "The thread has woken up";
    }

    qDebug() << "The thread has finished it's work";
    emit finished();

    deleteLater();
}

