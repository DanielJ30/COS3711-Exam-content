# October-November 2022

---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.

---

## Case:
All businesses need to manage their communication, and the simplified scenario used in this
examination is based on communication strategies. The idea is that a user can select a type of
communication channel and have a message sent out on that channel at some specific point
in time. The application itself allows the user to set up the required options and just the strategy
and message will be displayed for the purposes of a brief history of messages sent – See Figure

![Oct-Nov-2021_Q1_Image.png](..%2FResources%2FOct-Nov-2021_Q1_Image.png)

## Question 1 [11 marks]
Apply the strategy design pattern to the scenario above that would also adhere to the following
requirements.
1. There are currently 3 basic strategies/channels for communication: Signal, SMS, and
   WhatsApp. Your design should include a strategy for each channel.
2. All that is needed to create one of these is a type name.
3. Once an appropriate type has been created, a `setUp()` function would be used to populate
   object instance data members, and the `communicate()` function used to process the
   required communication.

A `CommunicationStrategy` UML class diagram has already been drawn up – see Figure 2.
Note that you may abbreviate this class name to ComStrat in your answers.

### Question 1.1:
Considering the scenario given and design decisions listed above, draw a UML class
diagram for the strategy pattern. You should include the necessary classes, class
attributes, class constructors and operations, and class relationships to make it clear you
understand how data will be managed and passed between classes. Label all
relationships indicated; however, you do not have to include the Client/GUI class nor
indicate access specifiers.
[You may use a software tool to create the UML class diagram. If you are hand drawing
this answer, you can use an underline to indicate italics in the UML class diagram.] (11)

### Preparation - Draw up this table and assign classes, relationships, methods and properties
![Oct-Nov-2021 Q1.1 Diagram_Prep.png](..%2FResources%2FOct-Nov-2021%20Q1.1%20Diagram_Prep.png)

### Draw the UML diagram
![Oct-Nov-2021 Q1.1 Diagram.png](..%2FResources%2FOct-Nov-2021%20Q1.1%20Diagram.png)




### Question 1.2:
The provided UML class diagram included some of the text in italics. What does this indicate? (1)

#### 1.2 - Answer:
```text
Class is abstract.
Method is pure virtual.
```

### Question 1.3:
Describe what the function of the `communicate()` function would be in this design pattern? (2)

#### 1.3 - Answer:
```text
Base class - Abstract, no implementation.
Derived classes - Implement actual sending of messages on appropriate platform.
```

### Question 1.4:
The decision has been taken to initially host this application using cloud computing.
Would you recommend a public or private cloud model? (1)


#### 1.4 - Answer:
```text
Public cloud: No capital expenditure, low initial cost/rapid deployment.
```

---

## Question 2
This question relates to the code for creating and setting up of the required strategies.
The `setUp()` function in the `CommunicationStrategy` class (see Figure 2) is used to
populate the data members in an instance object. This function does the following.
- It first checks that the user code meets a particular pattern.
- If the user code does not meet requirements, the function returns `false`. If the user code does, the function returns `true`.
- Additionally, if the user code meets requirements,
  - all data member values are populated, and
  - a signal (`created()`) is emitted that sends the communication strategy type and the message (separate by a colon) as a `QString`. See the viewing window in Figure 1.

### Question 2.1:
Write the code for the class definition for the `CommunicationStrategy` class (that is,
what would be in the header file). Ensure that all functionality shown in Figure 2 and that
given above is included. (7)

`NOTE: Note that if an object need to be run on a thread, it needs to inherit QObject. Also note that you cannot pass an object that has a parent to a thread.`

#### 2.1 - Answer:
- Declaration:
```c++

#ifndef COMMUNICATIONSTRATEGY_H
#define COMMUNICATIONSTRATEGY_H

#include <QObject>
#include <QDateTime>

class CommunicationStrategy : public QObject
{
    Q_OBJECT
public:
    CommunicationStrategy();
    bool setUp(QString uc, QDateTime dt, QString m);
    virtual void communicate() = 0;     // communicate is a pure virtual method now and can be overritten in derived classes

signals:
    void created(QString s);

protected:
    QString userCode;
    QDateTime send;
    QString message;
};

#endif // COMMUNICATIONSTRATEGY_H
```

### Question 2.2
Write the regular expression that can be used to check whether a string meets the following requirements:
- The first character should be a G, K, or W (for Gauteng, KwaZulu-Natal and Western Cape).
- The second character could be any uppercase alphabetic character.
- This should be followed by one or more lowercase alphabetic characters or digits.
- The final character should be the same as the first character.

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

#### 2.2 - Answer:
```c++
// ([GKW])([A-Z])([a-z\d]+)\1   OR  ([GKW])([A-Z])([a-z0-9]+)\1
// The sections are grouped by parenthesis "()"
// And are seen as:
//  Group 1 - ([GKW])
//  Group 2 - ([A-Z])
//  Group 3 - ([a-z\d]+)

// The trailing \1 means that it should repeat Group 1
// If you put a trailing \2 then you want it to repeat Group 2
// If you put a trailing \3 then you want it to repeat Group 3 etc.

// When used with QRegularExpression
QRegularExpression re("([GMK])([A-Z](a-z0-9)+)\\1");

// When just provided (not a QRegularExpression)
([GMK])([A-Z](a-z0-9)+)\1
```

### Question 2.3:
Write the code for `bool CommunicationStrategy::setUp(QString uc, QDateTime dt, QString m)`. Use the information you have so far in this question to guide you,
where the regular expression in 2.2 will be used to check the user code.
Note the structure of the signal sent out: “Strategy:message”. Without using a data
member within the class, the type of strategy or class (Signal, SMS, or WhatsApp) should
be indicated before the colon. (9)

#### 2.3 - Answer:

```c++
bool CommunicationStrategy::setUp(QString uc, QDateTime dt, QString m) {

    QRegularExpression re("([GMK])([A-Z](a-z0-9)+)\\1");
    QRegularExpressionMatch match(re.match(uc));

    if (match.hasMatch()) {
        userCode = uc;
        send = dt;
        message = m;

        QString strategy(QMetaObject().className());
        emit created(strategy + ":" + m);
        return true;
    }

    return false;
}
```

### Question 2.4:
The signal that is emitted by `setUp()` is picked up by the GUI/client code and used to
populate the viewing window in Figure 1. What various widgets could be used to hold
this information, explaining what would need to be in place to make such use
possible? (6)

#### 2.4 - Answer
```text
- QTextEdit / QPlain TextEdit - Can be used directly.
- QListWidget- Convenience class, model and view combined.
- QTableView** view. Requires a suitable model (QStandardItemModel), to be linked to

* Or other convenience widget.
** Or other view.
```

### Question 2.5:
The signal that is emitted by `setUp()` could be seen as an implementation of which
design pattern? Explain why you say so. (3)

#### 2.5 - Answer
```text
Observer Pattern
- Qt Signals and slots is an implementation of the Observer Pattern.
- CommunicationStrategy object is the 'Obeserved' object that notifies when something happens.
- Other connected objects are the 'Observers' that react / respond to the signal emitted by setUp()
```

### Question 2.6:
Based on the CommunicationStrategy class set up in 2.1, would the following code
be legal? Explain why or why not. Note that marks are allocated only for the reason
given. (2)
```c++
// assume cs is a pointer to some valid CommunicationStrategy
object
cs->setProperty("priority","high"); 
```

#### 2.6 - Answer
```text
Yes it is legal.
The CommunicationStrategy class inherits QObject, so properties can be set.
NOTE: It should have implemented the Q_OBJECT macro as well
No fixed properties are defined, so would set a dynamic property named "priority".
```

## Question 3
This question relates to the writing of the data in the viewing window to an XML file.
Assume that the data in the viewing window can be stored in QStringList list for use in
the writing-to-XML process, where each line consists of the string of characters as seen in the
viewing window in Figure 1. This list must be passed to an object instance of a class that
should be run as a thread.
The XML file should take the following format.
```xml
<communications>
    <communication channel="Signal">
        <message>Remember to get your COVID19 vaccination.</message>
    </communication>
    <communication channel="SMS">
        <message>Wishing you a happy festive season.</message>
    </communication>
    <communication channel="WhatsApp">
        <message>Good luck for the exams!</message>
    </communication>
</communications>
```


### Question 3.1:
The following code has been provided for the class header file. However, this is not
considered good practice. Change the code so that it meets what is considered good
practice and will support being run as a thread. (3)
```c++
class WriteToXML: public QThread
{
public:
    WriteToXML(QStringList s);
    void doWrite(); // does the write to file in XML
private:
    QStringList strlist;
}
```

#### 3.1 - Answer:
```c++
#ifndef WRITETOXML_H
#define WRITETOXML_H

#include <QObject>

class WriteToXML : public QObject
{
    Q_OBJECT

public:
    WriteToXML(QStringList s);

public slots:
    void doWrite(); //Does the write to file in XML

signals:
    void finished();


private:
    QStringList strList;
};

#endif // WRITETOXML_H
```

### Question 3.2
Assuming that the string list passed to WriteToXML has been saved to strList in the
class constructor, write the code for the doWrite() function so that each line in the
string list is written to file in the format above, using DOM. A portion of the code is given
below and you have to add the missing parts in the appropriate places. (16)
```c++
void WriteToXML::doWrite()
{
    QDomDocument doc;
    foreach(QString s, strlist)
    {
    
    }
    QFile file("data.xml");
    file.open(QIODevice::WriteOnly);
    file.close();
}
```

#### 3.2 Answer:
```c++
// Q3.2
void WriteToXML::doWrite()
{
    // QDom version - Not supported in CMAKE seemingly
    // This is what they asked in the exam 2021
    //    QDomDocument doc;
    //    QDomElement root(doc.createElement("communications"));
    //    doc.appendChild(root);

    //    QStringList items;

    //    foreach (QString s, strList) {
    //        items = s.split(":");

    //        QDomElement comm(doc.createElement("communication"));
    //        comm.setAttribute("channel", items[0]);
    //        root.appendChild(comm);

    //        QDomElement message(doc.createElement("message"));
    //        QDomText text(doc.createTextNode(items[1]));
    //        message.appendChild(text);
    //        comm.appendChild(message);
    //    }
    //    QFile file("data.xml");

    //    file.open(QIODevice::WriteOnly);

    //    QTextStream out(&file);
    //    out << doc.toString();
    //    file.close();

    // ---------------------------------------------------------------------------------------------------------------------------------------------------------------------

    // QXmlStreamWriter version - supported in CMAKE
    // This is what they will ask in the exam 2023

    QFile file("data.xml");
    file.open(QIODevice::ReadWrite);                        // Ensure file creation
    file.resize(0);                                         // Clear the contents of the file

    QXmlStreamWriter xmlStream(&file);

    xmlStream.setAutoFormatting(true);
    xmlStream.writeStartDocument();
    xmlStream.writeStartElement("communications");          // communications start

    QStringList items;

    foreach (QString s, strList) {
        items = s.split(":");

        xmlStream.writeStartElement("communication");       // communication start
        xmlStream.writeAttribute("channel", items[0]);

        xmlStream.writeTextElement("message", items[1]);    // message start and end

        xmlStream.writeEndElement();                        // communication end
    }
    xmlStream.writeEndElement();                            // communications end

    emit finished();
}
```

### Question 3.3
Write the code that would be included in the GUI/client code that would run an instance
of this class as a thread. There is no output that needs to be handled as the output is
written to file. Assume that no object instances have been created yet. (6)


#### 3.3 - Answer
```c++
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

### Question 3.4
When running the code that had been set up by a novice, the IDE gave the message
“QThread: Destroyed while thread is still running” and no data was written to file.
Explain what the problem could be and how to solve it. (5)

#### 3.4 - Answer
```text
The thread was declared with local scope and thus gets destroyed when the method returns before the thread has finished/ been destroyed.

Solution:
- Declare thread objects as class members (this would make them part of the Global scope within the class)
- Implement worked 'finished' signal to be emitted when worker task is completed, and connect to the thread quit() slot.
- Connect finished signals to thread and  worker deleteLater() slots.
```

### Question 3.5
Suppose that this XML file were to be read in to another application. One developer
noted that as DOM was used to write the file, DOM will have to be used to parse it again.
Comment on this statement. (2)
#### 3.5 - Answer
```text
Not necessary.
You can use SAX, DOM or QXmlStreamReader.
XML is a standard specification and can therefore be parsed by any method.
```