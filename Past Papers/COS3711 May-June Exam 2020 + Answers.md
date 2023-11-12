# May-June 2020

---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.

---

## Case:
Thousands of people take flights each day. For each fight, the origin, destination, and flight
number are stored. Additionally, for each passenger, the passenger name and ID number are
stored.

## Question 1:
The UML class diagram below has been proposed as a design for the `Flight` class.
![May-June-2020-Q1_Figure_1.jpg](..%2FResources%2FMay-June-2020-Q1_Figure_1.jpg)

### Question 1.1:
Which anti-pattern can be identified in the design of the Flight class? (1 mark)

#### 1.1 - Answer:
```text
The Blob
- Procedural-style design leads to one object with a lion’s share of the responsibilities, 
  while most other objects only hold data or execute simple processes. The solution includes 
  refactoring the design to distribute responsibilities more uniformly and isolating the 
  effect of changes.
```

### Question 1.2:
Using a UML class diagram, redesign the solution, adding any classes that you deem
necessary. You should take the functions and data members that are already present in
the UML class diagram into account when designing your updated solution, and add
functions where necessary to make new class interactions clear. Note that you are not
required to include passengers at this point yet. (8 marks)

#### 1.2 - Answer:
![May-June-2020-Q1.2jpg.jpg](..%2FResources%2FMay-June-2020-Q1.2jpg.jpg)

### Question 1.3:
A valid flight number is of one of the following forms: exactly three uppercase alphabetic
characters followed by 3 digits (CAW463, for example) or exactly two uppercase
alphabetic characters followed by 4 digits (BA6423, for example). Provide a regular
expression that would check whether a given flight number is valid. (7 marks)

#### 1.3 - Answer:
```c++
([A-Z]{3}[0-9]{3})|([A-Z]{2}[0-9]{4})

or (using \d character to represent digits)

([A-Z]{3}[\d]{3})|([A-Z]{2}[\d]{4})

or (with escaped characters in quotes)

"([A-Z]{3}[\\d]{3})|([A-Z]{2}[\\d]{4})"
```

### Question 1.4:
One way of storing the list of passengers on a flight is to use Qt’s parent-child facility.
Thus, a `Passenger` instance is a child of a `Flight` instance, where a `Passenger` class
is used to model passenger objects.

### Question 1.4.1:
Write the class header for the `Flight` class so that it may be used as the parent for
`Passenger` items. Include only the necessary code to implement the parent-child
functionality; you do not need to include the functions and data members from your
answer in 1.2. (1 mark)

#### 1.4.1 - Answer:
`Note: I am making use of QString as it is what is currently used instead of string`

```c++
class Flight : public QObject
{
public:
    Flight();
    QString toString();

private:
    QString flightNumber;
    QString origin;
    QString destination;
};
```

### Question 1.4.2:
Write the class header for a `Passenger` class so that it may be used as a child instance
of a `Flight` instance. It should have a passenger name and ID number as data
members, both of which are initialised via a parameterised constructor. (3 marks)


#### 1.4.2 - Answer:
`Note: I am making use of QString as it is what is currently used instead of string`

```c++
class Passenger : public Flight
{
public:
    Passenger(QString pN, QString idN);
    
private:
    QString passengerName;
    QString idNumber;
};
```

### Question 1.4.3:
Explain two ways you could use to add the `Passenger p` object as a child of a `Flight`
object named `f`. Provide example Qt code to show how these would be achieved. (5)

#### 1.4.3 - Answer:

```text
1. Using an inheritance based hierarchy.
2. Ensure that class Flight inherits from public QObject, then you can make use of the setParent method to specify the parent of a class
```
```c++
Passenger *p = new Passenger("Daniel", "1234");
Flight *f = new Flight();

p->setParent(f);
```

### Question 1.5:
As an alternative to the parent-child approach in 1.4, the list of `Passenger`s could be
stored in one of the following: `QStandardItemModel`, `QAbstractTableModel`, or
`QTableWidget`.

### Question 1.5.1:
Explain the differences between these three approaches. (3)

#### 1.5.1 - Answer:
```text
QStandardItemModel:
- Overview: QStandardItemModel is a general-purpose model class for use with Qt's item view classes (like QListView, QTreeView, and QTableView).
- Data Storage: It stores items as a hierarchical tree of QStandardItem objects. Each item can have text, icons, and other attributes.
- Flexibility: Offers flexibility in organizing data hierarchically. You can use it to create a structured model with rows and columns.
- Customization: Allows you to customize items extensively, but it might require more code to implement custom data structures.
- Usage: Suitable when you want to create a custom model with a complex structure for your data.

QAbstractTableModel:
- Overview: QAbstractTableModel is an abstract base class for providing a read-only table model for Qt's item views.
- Data Storage: Requires subclassing to provide an implementation. You need to implement methods like rowCount, columnCount, and data to define the structure and content of your model.
- Flexibility: Offers flexibility in defining the structure and handling of data. You can use it to create custom models for tabular data.
- Customization: Requires more code compared to QStandardItemModel but provides more control over the data structure and behavior.
- Usage: Suitable when you need a custom model for tabular data and want more control over the data structure and behavior.

QTableWidget:
- Overview: QTableWidget is a convenience class that provides a table view with a default model (QTableWidgetItem) that can be easily populated.
- Data Storage: Internally manages a table of items (QTableWidgetItem) organized in rows and columns.
- Flexibility: Easier to use for simple cases but may become less convenient for complex models or custom data structures.
- Customization: Provides less flexibility compared to custom models. The default item types may not be sufficient for complex use cases.
- Usage: Suitable for simple cases where a table view is needed, and a quick setup is desired. It's a more straightforward option if the structure of your data fits well with a table.
```

### Question 1.5.2:
Which of these three would you recommend, stating why you say so? (2)

#### 1.5.2 - Answer:
```text
QStandardItemModel as it provided general-purpose model class for use with Qt's item view classes and it stores items as a hierachical tree of QStandardItem objects.
You could make the initial item the parent (flight) and its children can be the passengers.
```

## Question 2:
The `Passenger` child objects of a `Flight` instance need to be written to an XML file using
`QXmlStreamWriter`; use the steps set out in this question to guide you. The XML file should
have the following format.
```xml
<passengerList>
    <passenger>
        <name>one</name>
        <identityNumber>1</identityNumber>
    </passenger>
    <passenger>
        <name>two</name>
        <identityNumber>2</identityNumber>
    </passenger>
</passengerList>
```

### Question 2.1:
Write the code necessary to access the child objects of the `Flight` object named f (in
1.4.3). Store this list in a variable named `list` that has the appropriate type. It is this list
that will be passed to the function that will write the XML file. (2)

#### 2.1 - Answer:
```c++
// Imagine this code was provided
Passenger *p = new Passenger("Daniel", "1234");
Flight *f = new Flight();

p->setParent(f);

// Now you can make use of the children() method to get the children of an object
QList<QObject*> list = f->children();
```

### Question 2.2
You need to use meta-objects to gain read access to the properties of each `Passenger`
instance. Rewrite the `Passenger` class header (from 1.4.2) to make this possible. (4)

#### 2.2 - Answer:
```c++
class Passenger : public Flight
{
    Q_OBJECT
    Q_PROPERTY(QString passengerName READ getPassengerName CONSTANT)
    Q_PROPERTY(QString idNumber READ getIdNumber CONSTANT)
public:
    Passenger(QString pN, QString idN);
    QString getPassengerName();
    QString getIdNumber();
private:
    QString passengerName;
    QString idNumber;
};
```

### Question 2.3:
Using the following code fragment as a guide, indicate how you would access the
`Passenger` child objects of a `Flight` instance stored in `list`. You should use the metaobject
to iterate through the child object’s properties so that they may be written to an
XML file. You need only write the code for the `write()` implementation.

```c++
class XMLWriter
{
public:
    XMLWriter(QString fn);
    void write(/* appropriate type */ list);
private:
    QXmlStreamWriter writer;
    QString filename;
};

XMLWriter::XMLWriter(QString fn): filename(fn)
{
}

// This is the code that you need to implement fully.
// Use the comments to guide your implementation.
void XMLWriter::write(/* appropriate type */ list)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    writer.setDevice(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    // create the root element
    for (int i=0; i< /* insert limit here */; i++)
    {
        // create appropriate XML opening and closing tags
        // get the Passenger object and its meta-object, then
        // loop through all the properties and create the
        // necessary XML tags (as per the example)
    }
    // close root tag
    writer.writeEndDocument();
    file.close();
}
```

#### 2.3 - Answer:
```c++
void XMLWriter::write(QList<Passenger*> list)
{
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    writer.setDevice(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    // create the root element
    writer.writeStartElement("PassengerList"); // Start the PassengerList element
    for (int i=0; i< list.count(); i++)
    {
        writer.writeStartElement("passenger"); // Start the passenger element

        Passenger *p = list.at(i);
        const QMetaObject *metaObject = p->metaObject();    // Get the metaObject for the provided passenger pointer named p
        QString metaObjectPassengerName = (metaObject->property(metaObject->indexOfProperty("passengerName"))).read(p).toString(); // Get the passengerName of the property
        writer.writeTextElement("name", metaObjectPassengerName);

        QString metaObjectIdNumber = (metaObject->property(metaObject->indexOfProperty("idNumber"))).read(p).toString(); // Get the idNumber of the property
        writer.writeTextElement("identityNumber", metaObjectIdNumber);
        writer.writeEndElement(); // End the passenger element
    }
    // close root tag
    writer.writeEndElement(); // End the PassengerList element
    writer.writeEndDocument();

    file.close();
}
```

### Question 2.4:
2.4 What two important benefits are there to using the meta-object to write an object’s
properties rather than the object’s getters? (2 marks)

#### 2.4 - Answer:
```text
1. Dynamic Property System:
- The meta-object system in Qt allows you to dynamically add properties to objects at runtime. 
  This is powerful because it provides a flexible way to associate additional data with 
  objects without modifying their class definitions. By using the Q_PROPERTY macro in 
  conjunction with the meta-object system, you can declare properties that can be manipulated at runtime. 
  This dynamic property system facilitates more dynamic and adaptable code.
  
2. Integration with Qt's Signals and Slots Mechanism:
- When you use the Q_PROPERTY macro in conjunction with the meta-object system, you can 
  automatically integrate properties with Qt's signals and slots mechanism. This means that 
  changes to the properties can automatically emit signals, allowing other parts of your 
  application to respond to changes in the object's state.
```

### Question 2.5:
This writing to an XML file partly follows the Serializer design pattern.

### Question 2.5.1:
Explain in detail how this follows the Serializer design pattern and why only partly
so. (2 marks)

#### 2.5.1 - Answer:
```text
The Serializer design pattern is a structural pattern that provides a mechanism to 
convert an object's state into a format that can be easily stored, transmitted, or 
reconstructed. The primary goal of the Serializer pattern is to facilitate the conversion 
of complex object structures into a format that can be easily handled, such as a 
string or a file.

If you're using Qt, the serialization process might also be influenced by Qt's own 
mechanisms for handling object properties, signals, and other features. 
This integration might introduce some differences or variations compared to a generic 
implementation of the Serializer pattern.

In summary, while writing to an XML file aligns with the general principles of the 
Serializer design pattern by converting an object's state into a format suitable for 
storage, there may be specific considerations, optimizations, or deviations from the 
pattern based on the requirements of the application or the characteristics of the 
framework being used (such as Qt).
```

### Question 2.5.2:
How do the encapsulation requirements of the Serializer design pattern differ from those
of the Memento design pattern? (4 marks)

#### 2.5.2 - Answer:
```text
The Serializer pattern and the Memento pattern have different encapsulation requirements 
driven by their distinct goals. The Serializer pattern focuses on making the object's 
state accessible for external representation while maintaining a level of format independence. 

The Memento pattern emphasizes hiding the internal state and providing a controlled 
interface for capturing and restoring that state, primarily for purposes like undo 
functionality.
```

## Question 3:
Along with flights and passengers, a database of available aircraft is also needed. The following
`Aircraft` UML class diagram and `AircraftDatabase` class have been proposed. The `QMap`
in the aircraft database maps an aircraft registration number to the `Aircraft` instance for that
particular registration. The sequence numbers provide a unique number for each aircraft.

![May-June-2020-Q3_Figure_1.jpg](..%2FResources%2FMay-June-2020-Q3_Figure_1.jpg)

```c++
class AircraftDatabase
{
public:
    AircraftDatabase();
    QString aircraftDetails(QString regnum) const;
private:
    QMap<QString, Aircraft> aircraft;
    static long sequenceNumber;
};
```

### Question 3.1:
It has been suggested that this database should follow a Singleton design pattern.

### Question 3.1.1:
Why would a Singleton be a good idea in such a case? (2 marks)

#### 3.1.1 - Answer:
```text
Benefits of having the database use the singleton pattern:

Centralized Access:
- A Singleton provides a single, centralized point of access to the database instance. This can be 
  beneficial in scenarios where you want to control and coordinate access to the database throughout 
  your application.

Resource Management:
- Databases often involve managing resources such as connections, connection pools, or caches. 
  A Singleton can help in efficiently managing these resources by ensuring that there is only one 
  instance of the database, preventing unnecessary duplication of resource-intensive operations.

Global Configuration:
- If your application requires a single, globally configured database instance, a Singleton can 
  provide a convenient way to encapsulate the configuration settings and ensure that they are applied 
  consistently across the application.

Consistent State:
- A Singleton helps maintain a consistent state for the database. Since there is only one 
  instance, changes made to the database state are visible to all parts of the application, reducing 
  the risk of inconsistencies that might arise from having multiple independent instances.

Lazy Initialization:
- Singleton pattern allows for lazy initialization, meaning that the database instance is created 
  only when it is first requested. This can be useful in scenarios where the database connection is 
  not needed immediately during the application startup, optimizing resource usage.

Thread Safety:
- Singleton patterns can be designed to be thread-safe, ensuring that multiple threads can safely 
  access and use the database instance. This is crucial in multithreaded applications to prevent 
  race conditions and ensure data integrity.

Simplifies Maintenance:
- A Singleton can simplify maintenance by providing a single point for updating database-related 
  functionality. If changes are needed, they can be made in one place, reducing the risk of 
  introducing errors that might arise from updating multiple instances.

Encapsulation:
- The Singleton pattern encapsulates the database access logic within a single class, promoting a 
  clean and modular design. This encapsulation can make the codebase more maintainable and understandable.
```

### Question 3.1.2:
Does this suggested class meet the requirements of a Singleton design pattern? If yes,
explain in detail why you say so; if no, explain what the problem is, and how the Singleton
should be implemented. You may include explanatory code if you find it necessary to
explain your answer. (5 - marks)

#### 3.1.2 - Answer:
```text
No the suggested class does not meet the requirements of a Singleton design pattern.
Corrections would include the following:
- Make the constructor private.
- Have a static instance data member.
- Provide a public static method to get the instance/create the initial instance of the database.
```

``Class header file updated``
```c++
class AircraftDatabase
{
public: 
    static AircraftDatabase* getInstance(); // Must be a static pointer
    QString aircraftDetails(QString regnum) const;
    
private:
    AircraftDatabase(); // Constructor must be private in singleton class
    static AircraftDatabase* instance; // Must be a static pointer of the AircraftDatabase class
    QMap<QString, Aircraft> aircraft;
    static long sequenceNumber;
}
```

### Question 3.2:
A search function, `search(QString reg)`, receives a `QString` parameter representing
an aircraft registration number, searches an `AircraftDatabase` instance, and outputs
the `Aircraft` data associated with the registration number to the standard output.

This search function needs to be run as a separate process, with its output managed by
the function `void Data::acceptAircraft()`.

Write the code necessary to start the search function as a separate process (passing
`"A6-EEY"` as a parameter) and have its output managed by the `acceptAircraft()`
function. Use the `start()` function declaration below to guide you.
```c++
void QProcess::start(const QString &program, const QStringList &arguments, QIODevice::OpenMode mode = ReadWrite)
```
You should include instance creation where necessary. (7 marks)

#### 3.2 - Answer:
```text
Do we need to do QProcess stuff?
```

### Question 3.3:
The design team decided that a Factory Method design pattern should be used to move
the responsibility for creating `Aircraft` instances to a separate class
(`CreateAircraft`). Assuming that the class definition for this class exists, write the code
for the function that will implement the Factory Method pattern (as it would appear in the
`CreateAircraft` implementation file). You may assume that only two types of aircraft
will be involved (where the class names are given in brackets and are derived from
`Aircraft`): Boeing 373-800 (`B738`), and Airbus A380-800 (`A388`). (3 marks)

#### 3.3 - Answer:
```c++

Aircraft* Aircraft::CreateAircreaft(QString className)
{
    if(className.startsWith('A')) // Airbus
    {
        return new Airbus(className);
    } else if(className.startsWith('B')) // Boeing
    {
        return new Boeing(className);
    }
}
```

### Question 3.4:
Considering all the functionality that has been included in this scenario (flights, reading
and writing lists of flights, passengers on flights, managing and writing passenger lists,
an aircraft database), describe how a Façade design pattern may be of use. (4 marks)

#### 3.4 - Answer:
```text
The Facade design pattern can be beneficial in the described scenario involving flights, passengers, 
and an aircraft database by providing a simplified and unified interface to a set of interfaces in a 
subsystem. 

Here's how a Facade pattern could be useful in this context:

1. Complexity Hiding:
- Integration of Multiple Modules:
    - In a system with flights, passengers, and an aircraft database, there are likely multiple 
    modules and classes handling different aspects of these entities. A Facade can provide a unified 
    interface that hides the complexities of the interactions between these modules. 
    Clients interacting with the Facade don't need to be aware of the intricate details of each 
    subsystem.

2. Unified Interface:
- Simplified Access to Functionality:
    -The Facade can offer a simplified and high-level interface for common operations related to 
    flights, passengers, and the database. Clients can interact with the Facade to perform tasks 
    without needing to know the intricacies of the underlying subsystems.

- Coordinated Operations:
    - If certain operations involve coordination between different subsystems (e.g., booking a 
    passenger on a flight involves updating both the flight and passenger subsystems), the Facade 
    can handle these complexities behind a single, easy-to-use interface.

3. Subsystem Decoupling:
- Loose Coupling:
    - The Facade pattern helps in achieving loose coupling between clients and subsystems. Changes 
    in the subsystems (such as adding new functionality or modifying existing behavior) can be 
    isolated within the Facade, minimizing the impact on the client code.

4. Improved Maintainability:
- Centralized Maintenance:
    - If there are changes or updates needed in how the subsystems interact, the Facade provides a 
    centralized point for making modifications. This can improve maintainability by consolidating 
    changes within the Facade rather than requiring modifications across multiple client classes.

- Simplified API for Clients:
    - Clients interact with a simplified API provided by the Facade, making it easier for developers 
    to understand and use the functionality. This can be especially beneficial for developers who 
    do not need to work with the detailed functionalities of each subsystem.
    
The Facade pattern, helps in simplifying the client code, hiding subsystem complexities, and 
providing a unified and easy-to-understand interface for common operations involving flights, 
passengers, and the aircraft database.
```