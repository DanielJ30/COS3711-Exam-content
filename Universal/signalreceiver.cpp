
#include "signalreceiver.h"

SignalReceiver::SignalReceiver()
{
    string = "You will pass";
    number = 100;
    flag = true;
}

void SignalReceiver::receiveString(QString s)
{
    string = s;
    qDebug() << "String signal received. String received: " << s;
}

void SignalReceiver::receiveInt(int i)
{
    number = i;
    qDebug() << "Int signal received. Int received: " << i;
}

void SignalReceiver::receiveBool(bool b)
{
    flag = b;
    qDebug() << "Bool signal received. Bool received: " << b;
}

void SignalReceiver::receiveAll(int i, QString s, bool b)
{
    number = i;
    string = s;
    flag = b;
    qDebug() << s << b << ", with " << i << "%";
}

