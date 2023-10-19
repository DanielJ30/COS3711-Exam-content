
#include "signalsender.h"

SignalSender::SignalSender()
{
    number = 100;
    string = "Will you pass";
    flag = true;
}

void SignalSender::sendSignals()
{
    //sends the string across a signal
    emit signalString(string);

    //sends the bool across a signal
    emit signalBool(flag);

    //sends the int across a signal
    emit signalInt(number);

    //sends all the variables across
    emit signalAll(number, string, flag);

}

