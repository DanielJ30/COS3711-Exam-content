#### UDP socket receiver

https://doc.qt.io/qt-6/qudpsocket.html

NOTE: In order to use Sockets, you must add `find_package(Qt6 REQUIRED COMPONENTS Network)` to your CMAKE file:

```c++
cmake_minimum_required(VERSION 3.5)

project(StoreManagementApp-Receiver VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Network)
```



```c++
#include "storemanagementappreceiver.h"

#include <QFormLayout>
#include <QLabel>
#include <QTextEdit>
#include <QUdpSocket>
#include <QThread>

StoreManagementAppReceiver::StoreManagementAppReceiver() :
    receiverUILayout(new QFormLayout),
    wdgReceiverUI(new QWidget),
    lblTransactionsXml(new QLabel("Transactions XML:")),
    txtTransactionsXml(new QTextEdit()),
    socket(new QUdpSocket(this))
{
    setCentralWidget(wdgReceiverUI);

    socket->bind(2006, QUdpSocket::ShareAddress); // Address to bind to
    connect(socket, &QUdpSocket::readyRead, this, &StoreManagementAppReceiver::processBroadcastedMessage);

    txtTransactionsXml->setReadOnly(true);
    receiverUILayout->addRow(lblTransactionsXml);
    receiverUILayout->addRow(txtTransactionsXml);
    wdgReceiverUI->setLayout(receiverUILayout);

    setWindowIcon(QIcon(":/store_splash.png"));
    setMinimumSize(300, 300);
    resize(500, 350);
    setWindowTitle(tr("Transaction XML Receiver"));
}

void StoreManagementAppReceiver::processBroadcastedMessage()
{
    QByteArray datagram;
    while (socket->hasPendingDatagrams())
    {
        datagram.resize(int(socket->pendingDatagramSize())); // Set the datagram size to be equal to the pending receiving datagram broadcast
        socket->readDatagram(datagram.data(), datagram.size()); // Read the broadcasted message
        txtTransactionsXml->setText(tr(datagram.constData())); // Set the txt to be the transactions XML
    }
}
```

### Sleeping a thread:
```c++
QThread::currentThread()->msleep(750);
```

### Another example
```c++
UDPSocketTest::UDPSocketTest()
{

}

void UDPSocketTest::initSocket()
{

    udpSocket = new QUdpSocket(this);
    udpSocket->connectToHost(QHostAddress::LocalHost, 2006);
    udpSocket->bind(2006);


    QString test = "testString";

    QByteArray datagram = test.toUtf8();
    udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, 2006);
    int i = 1;

    while (i < 100) // Always run
    {
        udpSocket->writeDatagram(datagram, QHostAddress::LocalHost, 2006);
        i++;

        QThread::currentThread()->msleep(2000); // Sleep the thread for 2 seconds and then run again
        readPendingDatagrams();
    }

}

void UDPSocketTest::readPendingDatagrams()
{
    QByteArray datagram;
    while (udpSocket->hasPendingDatagrams()) {
        datagram.resize(int(udpSocket->pendingDatagramSize())); // Set the datagram size to be equal to the pending receiving datagram broadcast
        udpSocket->readDatagram(datagram.data(), datagram.size());

        qDebug() << datagram.constData();
    }
}

```