# Oct-Nov 2021
### Question 3.3
Write the code that would be included in the GUI/client code that would run an instance
of this class as a thread. There is no output that needs to be handled as the output is
written to file. Assume that no object instances have been created yet. (6)


#### 3.3 - Answer
```c++
#include <QThread>
#include <QStringList>

// Needs to be in a method - Currently just in the void :)

// Q3.3
QStringList list = { "Signal:Remember to get your COVID19 vaccination.", "SMS:Wishing you a happy festive season.", "WhatsApp:Good luck for the exams!" };

// Both examples work as intended

// Eg. 1 - Using classic signals and slots specification for connect function
// Declare writeXml object and thread object
WriteToXML *writeXml = new WriteToXML(list);
QThread *thread = new QThread();

// Move the object to the thread
writeXml->moveToThread(thread);

// Connect signals and slots
QObject::connect(thread, SIGNAL(started()), writeXml, SLOT(doWrite()));                 // Connect thread's 'started' signal to the writeXML object's 'doWrite' slot
QObject::connect(writeXml, SIGNAL(finished()), thread, SLOT(quit()));                   // Connect writeXml's 'finished' signal to the thread's 'quit' slot
QObject::connect(writeXml, SIGNAL(finished()), writeXml, SLOT(deleteLater()));          // Connect writeXml's 'finished' signal to the writeXml's 'deleteLater' slot
QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));              // Connect writeXml's 'finished' signal to the thread's 'deleteLater' slot
thread->start();

// ---------------------------------------------------------------------------------------------------------------------------------------------------------------------

// Eg. 2 Using scope declaration decorator
// Declare writeXml object and thread object
WriteToXML *writeXml2 = new WriteToXML(list);
QThread *thread2 = new QThread();

// Move the object to the thread
writeXml2->moveToThread(thread2);

// Connect signals and slots
QObject::connect(thread2, &QThread::started, writeXml2, &WriteToXML::doWrite);          // Connect thread2's 'started' signal to the writeXML2' object's 'doWrite' slot
QObject::connect(writeXml2, &WriteToXML::finished, thread2, &QThread::quit);            // Connect writeXml2's 'finished' signal to the thread2's 'quit' slot
QObject::connect(writeXml2, &WriteToXML::finished, writeXml2, &QThread::deleteLater);   // Connect writeXml2's 'finished' signal to the writeXml2's 'deleteLater' slot
QObject::connect(thread2, &QThread::finished, thread2, &QThread::deleteLater);          // Connect writeXml2's 'finished' signal to the thread2's 'deleteLater' slot
thread2->start();
```

### Sleeping a thread:
```c++
QThread::currentThread()->msleep(750);
```