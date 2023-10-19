#### UDP socket receiver

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