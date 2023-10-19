
#ifndef SIGNALRECEIVER_H
#define SIGNALRECEIVER_H


#include <QObject>
#include <QDebug>

class SignalReceiver: public QObject
{
    Q_OBJECT
public:
    SignalReceiver();

public slots:
    //receives a string from a signal
    void receiveString(QString s);

    //receives an int from a signal
    void receiveInt(int i);

    //receives a bool from a signal
    void receiveBool(bool b);

    //receives 3 variables from a signal
    void receiveAll(int i, QString s, bool b);

private:
    QString string;
    int number;
    bool flag;
};

#endif // SIGNALRECEIVER_H
