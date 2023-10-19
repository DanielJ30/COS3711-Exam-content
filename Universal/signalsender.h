
#ifndef SIGNALSENDER_H
#define SIGNALSENDER_H


#include <QObject>


class SignalSender: public QObject
{
    Q_OBJECT
public:
    SignalSender();

    //function to send signals
    void sendSignals();

signals:
    void signalString(QString s);
    void signalInt(int i);
    void signalBool(bool b);
    void signalAll(int i, QString s, bool b);

private:
    int number;
    QString string;
    bool flag;
};

#endif // SIGNALSENDER_H
