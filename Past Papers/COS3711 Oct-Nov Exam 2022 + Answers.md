# October-November 2022

---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.

---

## Case:
Most people like chocolate. “Chocolate is a food made from roasted and ground cacao seed kernels, that is available as a liquid, solid or paste, on its own or as a flavouring agent in other foods” (https://en.wikipedia.org/wiki/Chocolate). Also, as most dark chocolates are vegan, they can be enjoyed by people with stricter dietary choices. Chocolate can also be found in many forms: bars, slabs, and in drinks, to name just a few.
For the sake of this scenario, you may assume the following about designing an application that manages various types of chocolate.
- Initially it has been decided that chocolates can come in bars and slabs. A user should not be able to create instances of a basic chocolate that is neither a bar nor a slab.
- All chocolates have a name (in the form of a string) and a flag indicating whether it is vegan or not. They should also all have a string representation of their data members.
- You are required to include the number of blocks there are for a slab chocolate.
- Each instantiated chocolate should have a unique serial number, starting at 1 and incrementing by 1 for each new chocolate instantiated. This should not be managed outside the chocolate class hierarchy.
- There is a register of chocolates that holds all instantiated chocolate objects.
- An appropriate design pattern should be used that allows the user to choose the kind of chocolate to instantiate.

## Question 1
### Question 1.1:
Considering the scenario given above, draw a partial UML class diagram that captures
the scenario. You should include the necessary classes, class attributes, and class
relationships that are mentioned in the scenario, including class member access
specifiers (+, -, #). `You do not have to include the Client/GUI class nor indicate
constructors or other methods in the classes you specify.`
[You may use a software tool to create the UML class diagram. Use underlining to
represent italics in hand-drawn UML class diagrams.] (14)

#### 1.1 - Answer:
- Preparation - Draw up this table and assign classes, relationships, methods and properties

![Oct-Nov-2022 Q1.1 Diagram_Prep.jpg](..%2FResources%2FOct-Nov-2022%20Q1.1%20Diagram_Prep.jpg)

- Draw the UML diagram

![Oct-Nov-2022 Q1.1 Diagram.png](..%2FResources%2FOct-Nov-2022%20Q1.1%20Diagram.png)

### Question 1.2:
Write the class declaration and implementation code for the `Chocolate` class. Include the following requirements when doing so:
- All requirements from the scenario on page 2: instantiation restrictions, string representation (that returns the data values in a comma-separated list), and unique serial number.
- There should be only one constructor that will allow for optional arguments for the data members. (10)

#### 1.2 - Answer:
- Declaration:
```c++
Class declaration (header file):


#ifndef CHOCOLATE_H
#define CHOCOLATE_H

#include <QString>

class Chocolate
{
public:
    Chocolate(QString n = "No Name", QString v = "Yes");    // No defaut Costructor
                                                            // Only user defined constructor with default arguments

    virtual ~Chocolate();                                   // Virtual deconstructor
    virtual QString toString() = 0;                         // Pure virtual method, Abstract Base class, 
                                                            // the ' = 0 ' part makes it PURE virtual

protected:                                                  // Protected - Accessible from derived classes
    QString name;
    QString isVegan;
    int serialNum;

private:
    static int count;                                       // Static data member
};

#endif // CHOCOLATE_H
```
- Implementation:
```c++
Class implementation (cpp file):


#include "chocolate.h"

int Chocolate::count = 0;           // Static member initialize outside of Class
                                    // Uses scope resolution operator (the Chocolate part)

Chocolate::Chocolate(QString n, QString v)
    : name(n),                      // Initialize the properties in this area and not in the curly brace part
    isVegan(v)
{
    count++;                        // Serial number count incremented in Constructor
                                    // Static member - belongs to class, not individual objects
    serialNum = count;              // Current value assigned to object data member
}

Chocolate::~Chocolate()
{

}

QString Chocolate::toString()
{
    // Pure virtual method can be defined in base class
    // This part is common to all derived classes
    // Base class implementation is used in derived classes

    QString outString(QString("NameL %1, Vegan: %2, Serial number: %3")
                          .arg(name)
                          .arg(isVegan)
                          .arg(serialNum));

    return outString;
}
```

### Question 1.3:
Based on the scenario, is Chocolate c; valid code? Explain clearly why you say so.
The mark is only awarded for the reasoning. (2)

#### 1.3 - Answer:
```text
No, Chocolate is an Abstract class and you cannot instantiate objects of an Abstract class
```

### Question 1.4:
It has been decided to make the Chocolate class a QObject.
```c++
class Chocolate : public QObject
{
    …
};
```

#### Question 1.4.1:
Give one major benefit of making Chocolate inherit from QObject. (1)

#### 1.4.1 - Answer:
```text
Signals and Slots, Reflection, Threading (QThread)
```

#### Question 1.4.2:
Besides what is given in the scenario before question 1, assume that CouvertureChocolate inherits from Chocolate. Would the following code (that passes
an instance of CouvertureChocolate to a display() function) be legal?
Explain clearly why you say so. The marks are only awarded for the reasoning. (2)

```c++
CouvertureChocolate cChoc;
display(cChoc);
```

#### 1.4.2 - Answer:
```text
No, You cannot pass a QObject by value.
This makes a copy of the object.

QObject has no public copy constructor.

(CouvertureChocolate inherits Chocolate, which inherits QObject)

You must pass QObjects by reference, or pointer.
```

---

## Question 2
The intention is to scan text files for references to vegan chocolates. This task will be taken on
by a class that is to be run as a thread.

### Question 2.1:
Write the class definition of the `Scan` class, which is to be run as a thread, that will be
used to count the number of times vegan chocolates is mentioned in a piece of text. The
filename to scan will be passed to the class instance, and the number of occurrences
should be returned to the calling function once the scan is complete. Include all
functionality that would be required so that it conforms to best practice. Use function and
variable names that will make it clear what the purpose of the function or variable is. (7)

`NOTE: Note that if an object need to be run on a thread, it needs to inherit QObject. Also note that you cannot pass an object that has a parent to a thread.`

#### 2.1 - Answer:
- Declaration:
```c++

#ifndef SCAN_H
#define SCAN_H


#include <QObject>


class Scan : public QObject                         // Must inherit QObject (Required for QThread as QThread inherits from QObject)
{
    Q_OBJECT                                        // Include Q_OBJECT macro in order for it to work properly
public:                                             // Pass file name to constructor
    Scan(QString fName, QObject *parent = nullptr); // NOTE: If you move an object to a thread, it may NOT have a parent

public slots:
    void countVegan();                              // Public slot to process file

signals:
    void returnCount(int count);                    // Return result of scan
    void finished();                                // Signal required to delete thread / worker

private:
    QString m_fileName;
};

#endif // SCAN_H
```

### Question 2.2:
It has been decided to use regular expressions to scan the file. Write the regular
expression, in quotes, that can be used to check for the words “vegan chocolate” or
“vegan chocolates” in the provided text file. You should not use the pipe symbol (|) and
ensure that you use escape characters correctly. (4)

`Note: when using QRegularExpression you need to escape your string literals like backslash. If you use a backslash in a string, then you have to escape it in the string with another backslash`

#### 2.2 - Answer:
```c++
// \b - Defines the word boundary (Its where a word starts or ends)
// ? - 0 or 1 instances of the selection in the group. If not in a group, then it relates to value before it.
// * - 0 or more instances of the selection in the group. If not in a group, then it relates to value before it.
// + - 1 or more instances of the selection in the group. If not in a group, then it relates to value before it.
// (a|b) a or b - This wasn't used, but is useful to know (Its a logical OR)


// When used with QRegularExpression
QRegularExpression re("\\bvegan chocolate[s]?\\b");
OR
QRegularExpression re("\\bvegan chocolate(s)?\\b");
OR
QRegularExpression re("\\bvegan chocolates?\\b");


// When just provided (not a QRegularExpression)
\bvegan chocolate[s]?\b
OR
\bvegan chocolate(s)?\b
OR
\bvegan chocolates?\b
```

### Question 2.3:
The following code stub is used to scan a list of files and collect the data returned from
the scanning process.

```c++
QStringList listOfFiles; // contains list of all files to be scanned
foreach (QString filename, listOfFiles)
{
    // use threading to scan the file
    // collect the number of mentions in a QList<int> named "counts"
}
```
This data is to be written to an XML file in the following format.

```xml
<fileCounts>
    <file name="filename_1">    // the name of the first file in the list
        <count>23</count>       // the count for this file
    <file name="filename_2">    // the name of the second file in the list
        <count>5</count>        // the count for this file
    . . .                       // and so on
</fileCounts>
```

Using the partial code given below, and assuming that `QStringList listOfFiles` and
`QList<int> counts` are accessible by this code, complete the code as indicated so that
the required XML text above will be generated using DOM. (11)
```c++
/*type*/ domDoc;
QDomElement root = /*function*/("fileCounts");

// set up any initial variables if required

// loop through all the items adding them to the XML text as necessary
```

#### 2.3 - Answer:

```c++

#include <QCoreApplication>
#include <Qdebug>
#include <QtXml\QDomDocument>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // 2.3

    QStringList listOfFiles;
    QList<int> counts;


    QDomDocument doc;
    QDomElement root = doc.createElement("fileCounts");
    doc.appendChild(root);

    QDomElement file, count;
    QDomText countText;

    // Loop through list items
    for (int pos = 0; pos++ < listOfFiles.count(); pos++) {
        file = doc.createElement("file");
        file.setAttribute("name", listOfFiles.at(pos));
        root.appendChild(file);

        count = doc.createElement("count");
        countText = doc.createTextNode(QString::number(counts.at(pos)));
        count.appendChild(countText);

        file.appendChild(count);
    }

    qDebug() << doc.toString();
    return a.exec();
}
```

## Question 3
Ignoring bars and slabs of chocolate, the chocolate manufacturer wants to have a range of
dark, milk, and white chocolate as sub-types of chocolate.
The following constructors are to be used.
```c++
DarkChocolate("NightTime", "yes", 85); // passing chocolate name, vegan status, and percent chocolate
MilkChocolate("Jersey", "no"); // passing only chocolate name and vegan status
WhiteChocolate("Fairland", "no", "no"); // passing chocolate name, vegan status, and whether it contains vanilla
```
It is required that the following be implementable (one function to create these three types of
chocolate).
```c++
Chocolate *choc = createChocolate(/* pass the type, name, vegan status and optional third parameter*/);
```

### Question 3.1:
Which design pattern is being suggested here? (1)

#### 3.1 - Answer:
```text
Factory method
```

### Question 3.2
Write the class definition for the class that would be used to implement this design pattern
based on the scenario at the start of this question. (4)

#### 3.2 Answer:
```c++

#ifndef CHOCOLATEFACTORY_H
#define CHOCOLATEFACTORY_H

#include "chocolate.h"

#include <QString>
#include <QVariant>


class ChocolateFactory
{
public:
    ChocolateFactory();

    // QVariant will allow us to capture any datatype
    // It has also been provided a default value of -1 for checking the input in the various constructors
    Chocolate* createChocolate(QString type, QString name, QString vStatus, QVariant item = -1);
};

#endif // CHOCOLATEFACTORY_H
```

### Question 3.3
The following is a class that that maintains a list of types of `Chocolate`s created by the
`createChocolate()` function.
```c++
class ChocolateList
{
public:
    ChocolateList();
    void addChocolate(/*type*/);
private:
    QMap</*key*/, /*value*/> darkChocolates;
    QMap</*key*/, /*value*/> milkChocolates;
    QMap</*key*/, /*value*/> whiteChocolates;
}
```
Considering the scenario at the start of this paper (on page 3), answer the following
questions.

### Question 3.3.1
What parameter would be passed to the addChocolate() function? (1)

#### 3.3.1 - Answer
```text
Chocolate *chocolate.
A pointer to a Chocolate object.
```

### Question 3.3.2
In the `ChocolateList` class, there is only one `addChocolate()` function with one
parameter, but three lists, one for each kind of chocolate. Without adding any further
data members to any of the classes in the `Chocolate` hierarchy but allowing the
`Chocolate` class to inherit from `QObject` (as in question 1.4), how would you propose
the `addChocolate()` function determine which of the three lists a `Chocolate` instance
passed to the class should be added? (2)

`NOTE: QMetaObject and reflection now becomes available`

#### 3.3.2 - Answer
```c++

#include "chocolatelist.h"

#include <QMetaObject>

ChocolateList::ChocolateList()
{

}

void ChocolateList::addChocolate(Chocolate* c)
{
    QString className;
    const QMetaObject *meta = c->metaObject();
    className = meta->className();

    if (className == "DarkChocolate") {
        darkChocolates.insert("dark", 1);           // Name, percentage chocolate
    }
    else     if (className == "MilkChocolate") {
        milkChocolates.insert("milk", "no");        // Name, vegan status
    }
    else     if (className == "WhiteChocolate") {
        whiteChocolates.insert("white", "yes");     // Name, contains vanilla
    }

}
```

### Question 3.3.3
What piece of data would you use as the key for the darkChocolates QMap, and why do you say so? (2)

#### 3.3.3 - Answer
```text
Any unique identifier.
```

### Question 3.3.4
It has been decided that a user should only be able to create one instance of the
ChocolateList class. Rewrite this class so that this requirement is met using a standard
design pattern. (4)

#### 3.3.4 - Answer
```c++
Singleton design pattern:

#ifndef CHOCOLATELIST_H
#define CHOCOLATELIST_H

#include "chocolate.h"

#include <QMap>
class ChocolateList
{
public:
    static ChocolateList* getInstance();        // Public getInstance() method returns the only instance of the ChocolateList
                                                // Must be static
    ~ChocolateList();
    void addChocolate(Chocolate* c);

private:
    ChocolateList();                            // Constructor is private (this is a standard in the singleton design pattern)
    static ChocolateList *instance;             // The static pointer to the only instance of the list
    QMap<QString, int> darkChocolates;          // Name, Percentage chocolate
    QMap<QString, QString> milkChocolates;      // Name, Vegan status
    QMap<QString, QString> whiteChocolates;     // Name, Contains vanilla

};

#endif // CHOCOLATELIST_H
```

## Question 4
A model-view approach can be used to manage and display a list of instantiated `Chocolate` object data.

### Question 4.1
Discuss three different general techniques that are open to a Qt programmer to manage
and display this data using a model-view approach. Explain how the technique would be
implemented (mentioning specific Qt classes as examples that may be appropriate in
this scenario), including what other factors need to be considered when implementing
the technique. (9)

#### 4.1 - Answer
```text
1. Pre-defined models / views: Use pre-defined models and / or views.
- QListView, QTableView, QStringListModel, QStandardItemModel.
- Reasonably flexible - data is separated from the view, can use more than one view on same data.
- Delegates can be used to modify appearance of data in the View.

2. Abstract models / views: Inheritance using abstract base classes.
- QAbstractItemModel,
- QAbstractListModel,
- QAbstractTableModel,
- QAbstractItemView.
- Most flexible approach, can customize models / views, but most complicated method.

3. Combined model / view - convenience classes: Model and View combined into one convenience widget.
- QListWidget, QTableWidget, QTreeWidget.
- asiest to use, but least flexible.
```

### Question 4.2
Suppose there is a GUI class (which is the main user interface), and a MyModelView
class that implements the model-view approach proposed in this question. If you were
to use the Memento pattern to set up a backup and restore facility for MyModelView,
answer the following questions.

### Question 4.2.1
Which class would create the memento? (1)

#### 4.2.1 - Answer
```text
Originator - MyModelView.
Calls createMemento() method to instantiate a ChocolateMemento object.
Caretaker initiates the process.
```

### Question 4.2.2
Which class would contain the data that is to be backed up? (1)

#### 4.2.2 - Answer
```text
Originator - MyModelView (Model manages data, not the view).
Data is actually stored in the Memento itself.
```

### Question 4.2.3
Which class would hold on to the created memento? (1)

#### 4.2.3 - Answer
```text
Caretaker - MainGUI
```

### Question 4.3
Given the following declarations
```c++
class Window : public QMainWindow
QTcpServer *tcpServer
QTcpSocket *tcpSocket
```

Reorder the following statements into the order in which they would be performed by a
TCP server application listening for, and processing, connections. Remember that
`connect()` statements may have limited/function scope, so you may assume that you
cannot list them all at the start of the application. You may simply write down the numbers
of the statements in the correct order.

```c++
1. connect(tcpSocket, &QTcpSocket::readyRead, this,
   &Window::readMessage);
2. connect(listenForConnection, &QPushButton::clicked, this,
   &Window::setUp);
3. connect(tcpServer, &QTcpServer::newConnection, this,
   &Window::handleConnection);
4. QByteArray data(tcpSocket->readAll());
5. tcpServer->listen(QHostAddress::Any, 5555)
6. tcpSocket = tcpServer->nextPendingConnection(); (3)
```

#### 4.3 - Answer
```text
2, 3, 5, 6, 1, 4
```
