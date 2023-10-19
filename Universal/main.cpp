
#include <QCoreApplication>
#include <QThread>
#include "xmlwriter.h"
#include "regularexpressiontester.h"
#include "signalreceiver.h"
#include "signalsender.h"
#include "threadworker.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);


    //////////////////////////////////////////
    //ONLY USE CODE AS TEMPLATE OR REFERENCE//
    //////////////////////////////////////////


    //To use this program simply create which every class the question is based on
    //Call the functions of the class and write your own coding to test it.
    //eg. We need to write in xml format to a file
    //Then create an xml class and call the function on it

    //----XML WRITER (FILE AND META PROPERTIES)----//
    //Use to write something to xml format then write it to a file
    //Can either use some list or some properties of a class
    //XMLWriter xmlWriter;
    //xmlWriter.WritePropertiesToFile();
    //xmlWriter.WriteToFile();

    //--REGULAR EXPRESSION TESTER--//
    //RegularExpressionTester regexTester("1([0-9]){2}[f|m]?[A-Z]([a-zA-Z]){2}");
    //regexTester.testExpression("102mAaag");

    //--SIGNAL AND SLOTS--//
    //SignalSender *sender = new SignalSender();
    //SignalReceiver *receiver = new SignalReceiver();
    //QObject::connect(sender, &SignalSender::signalAll, receiver, &SignalReceiver::receiveAll);
    //QObject::connect(sender, &SignalSender::signalInt, receiver, &SignalReceiver::receiveInt);
    //QObject::connect(sender, &SignalSender::signalString, receiver, &SignalReceiver::receiveString);
    //QObject::connect(sender, &SignalSender::signalBool, receiver, &SignalReceiver::receiveBool);
    //sender->sendSignals();


    //----WINDOWS AND WIDGETS----//
    //Use the window to test widgets
    //Add widgets to the ui form for testing
    //MainWindow w;
    //w.show();

    //----PROCESSES----//
    //Read QProcess documentation to see what the process's slots return
    //QProcess *process = new QProcess();
    //process->start("Name Of The .exe");
    //QObject::connect(process, &QProcess::readyReadStandardOutput, someclass, &SomeClass::someSlot);

    //----THREADS----//
    //Create a thread & class you want to be run on a thread (class must be a QObject)
    //Start the thread after the connects
    QThread *workerThread = new QThread();
    workerThread->setObjectName("Worker Thread");
    ThreadWorker *worker = new ThreadWorker();
    worker->moveToThread(workerThread);
    QObject::connect(workerThread, &QThread::started, worker, &ThreadWorker::workFunction);
    QObject::connect(worker, &ThreadWorker::finished, workerThread, &QThread::quit);
    QObject::connect(worker, &ThreadWorker::finished, worker, &ThreadWorker::deleteLater);
    QObject::connect(workerThread, &QThread::finished, worker, &ThreadWorker::deleteLater);
    workerThread->start();

    return a.exec();
}
