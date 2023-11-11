# May-June 2022

---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.

---

## Case:
Transporting cargo around the world is essential in ensuring that customers have access to the
goods they need and want, and an application to manage such cargo is to be implemented.

All such items are packaged in some sort of container (which, for the purposes of this scenario,
has a code represented as a string). Generally, there are two kinds of containers:
- (i) a box (with dimensions length, breadth, and height), and
- (ii) a cylinder (with dimensions height and diameter).

For transport, containers are packed onto pallets. Pallet details can be saved as a file, which
can also be read back in again.

## Question 1
### Question 1.1:
Considering the scenario given above, draw a partial UML class diagram that captures
the scenario. You should include the necessary classes, class attributes, and class
relationships that are mentioned in the scenario. You do not have to include the
Client/GUI class nor indicate constructors, access specifiers, or other methods in the
classes you specify.
[You may use a software tool to create the UML class diagram.] (13 marks)

#### 1.1 - Answer:
```
1. Container (Base - Abstract)
    - code: QString

2. Box (Inheritance - Container ---|>)
    - length: double
    - breadth: double
    - height: double

3. Cylinder (Inheritance - Container ---|>)
    - height: double
    - diameter: double
    
4. Pallet (Aggregation with Container ---<>)
    + details: QString
    + saveToFile()
    + readFromFile()
```

![May-June-2022 Q1.1.jpg](..%2FResources%2FMay-June-2022%20Q1.1.jpg)

### Question 1.2.2:
Which design pattern would be used in the scenario presented above? (1 mark)

#### 1.2.2 - Answer:

```text
Factory method
```

### Question 1.2.2:
Give two advantages of using design patterns when implementing solutions (2 marks)

#### 1.2.2 - Answer:
```text
- Design patterns help you write code faster by providing a clearer picture of how you are implementing the design.
- Design patterns encourage code reuse and accommodate change by supplying well-tested mechanisms for 
  delegation and composition, and other non-inheritance based reuse techniques.
```

### Question 1.3
The container code takes the following format.
- Initial B or C character to indicate whether the container is a box or cylinder.
- A 3-character serial number containing digits and upper and lowercase characters.
- A final character that matches the initial B or C character.

Write the regular expression (in quotes) that can be used to check that a container code
meets the required criteria. An example of a valid code is B0CxB. Ensure that you use
escape characters correctly. (8 marks)

#### 1.3 - Answer:
```c++
"^(B|C){1}[a-zA-Z0-9]{3}\\1$"
```

### Question 1.4
If an input mask were to be used for the input widget on the GUI, what string would be
used to ensure valid values for the code required in 1.3? (5 Marks)

#### 1.4 - Answer:

```c++
"ANNNA"

// Mask Character	Meaning
// A	character of the Letter category required, such as A-Z, a-z.
// a	character of the Letter category permitted but not required.
// N	character of the Letter or Number category required, such as A-Z, a-z, 0-9.
// n	character of the Letter or Number category permitted but not required.
// X	Any non-blank character required.
// x	Any non-blank character permitted but not required.
// 9	character of the Number category required, e.g 0-9.
// 0	character of the Number category permitted but not required.
// D	character of the Number category and larger than zero required, such as 1-9
// d	character of the Number category and larger than zero permitted but not required, such as 1-9.
// #	character of the Number category, or plus/minus sign permitted but not required.
// H	Hexadecimal character required. A-F, a-f, 0-9.
// h	Hexadecimal character permitted but not required.
// B	Binary character required. 0-1.
// b	Binary character permitted but not required.

// Meta Character	Meaning
// >	All following alphabetic characters are uppercased.
// <	All following alphabetic characters are lowercased.
// !	Switch off case conversion.
// ;c	Terminates the input mask and sets the blank character to c.
// [ ] { }	Reserved.
// \	Use \ to escape the special characters listed above to use them as separators.
```

### Question 1.5
It has been suggested that the code variable/data member of a container class should
be virtual. Comment on this suggestion.

#### 1.5 - Answer:
```text
You cannot have virtual data members in c++. Thus the code variable/data member cannot be made virtual.
```

## Question 2
The intention is to use reflective programming approaches.

### Question 2.1:
Write the class definition (found in the class header file) of the main container class so
that reflective programming approaches can be used. It should be possible to create
such container objects using a code that has already been provided; however, a default
code (`D999D`) should be used if no code is provided when the object is instantiated. (9)

#### 2.1 - Answer:
```c++
class Container : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString code READ getCode CONSTANT)
public:
    Container(QString c = "D999D")
    {
        code = c;
    }

    QString getCode();
private:
    QString code;
```

### Question 2.2:
The client wants to be able to add a comment to some of the container objects but does
not what this to be available as a general requirement for all container objects.
Considering the requirements for the cargo application so far, is it possible to add a
comment like “Fragile” to a container object named `container`? If so, explain why and
provide the code to do so; if not, explain in detail why not. Note that there are no marks
allocated for answering yes or no.


#### 2.2 - Answer:

```text
Yes you can by using the setProperty method on the container object
```
```c++
container->setProperty("comment", QString("Fragile"));
```

### Question 2.3
The following code is to be used to get property data from a container object.
```c++
1 QDomDocument d;
2 Container *c = new Container(); // assume a valid container
3 const QMetaObject *m = c->metaObject();
4 QDomElement basetag = d.createElement("container");
5 for (int i=1; i<m->propertyCount(); i++)
6 {
7   QMetaProperty prop = m->property(i);
8   QString propertyName = prop.name();
9   QString propertyValue = prop.read(c).toString();
10  QDomElement nametag = d.createElement(propertyName);
11  basetag.appendChild(nametag);
12  QDomElement valuetag = d.createElement(propertyValue);
13  nametag.appendChild(valuetag);
14 }
```
It is intended that the following XML structure be produced.
```c++
<container>
<1st property name>first property value</1st property name>
<2nd property name>first property value</2nd property name>
<3rd property name>first property value</3rd property name>
</container>
```

### Question 2.3.1
There are errors in the code provided above. Rewrite the necessary lines to correct the
error. You need only give the line number and the corrected code. (2 Marks)

#### 2.3.1 - Answer:
```text
Line 12 - Replacement text below
```
```c++
QDomText valuetag = d.createTextNode(propertyValue);
```

### Question 2.3.2
Would the comment referred to in 2.2 above be included as an XML tag produced by this
code? Explain clearly why you say so. Note that there are no marks for indicating yes or
no. (2 marks)

#### 2.3.2 - Answer:
No, Note that dynamic properties are added on a per instance basis, i.e., they are added to QObject, not QMetaObject


### Question 2.4
What do you understand by the term “meta-object”, and what is its major benefit? (2 marks)

#### 2.4 - Answer:
```text
Qt's meta-object system provides the signals and slots mechanism for 
inter-object communication, run-time type information, and the dynamic property system.

Benefits include:
1. Dynamic Features: The meta-object system provides a way to add dynamic features 
   to classes, such as signals, slots, and dynamic properties. This flexibility is 
   valuable in many GUI applications where dynamic behavior is essential.

2. Loose Coupling: Signals and slots enable a loosely coupled communication 
   mechanism between objects. This promotes a clean and modular design, making it 
   easier to maintain and extend code.

3. Run-time Reflection: The ability to introspect objects at runtime allows for 
   powerful runtime manipulations. This is particularly useful in scenarios where 
   you need to adapt to changing conditions or configure objects dynamically.
```

## Question 3
A model-view approach will be used to store the list of container codes that have been used.

### Question 3.1
What would be the differences between using a `QAbstractListModel` and a
`QListWidget` to store the list of container codes? (4 marks)

#### 3.1 - Answer:
```text
QAbstractListModel:
Purpose:
- Designed for creating custom models within the model/view framework.
- Suitable for handling complex data structures and custom data representations.

QListWidget:
Purpose:
- A convenience class that combines a simple model and view for list-based UIs.
- Quick and easy to use for basic list functionality.

Choosing Between Them:

Use QAbstractListModel if:
- You have a complex data structure.
- You need advanced customization and flexibility.
- You plan to use the same data in multiple views.

Use QListWidget if:
- You need a quick and simple solution.
- Your list requirements are basic, and a separate model is unnecessary.
- Customization needs are minimal, and default item appearance suffices.
```

### Question 3.2
Supposing the code “B111B” needed to be added to the list of container codes instance
named `model` below, write the code that would achieve this.
`QListWidget model`; (3 marks)

### 3.2 - Answer:
```c++
QListWidget model;
QListWidgetItem *code = new QListWidgetItem;
code->setText("B111B");
model->insertItem(row, code);
```

### Question 3.3
It has been suggested that the `model` from 3.2 also be displayed using a `QTableView`
on a separate tab in the application. How would you respond to this? (1 mark)

#### 3.3 - Answer:
```text
QListWidgets should be used for displaying simple lists of items, while QTableView is 
intended for displaying tabular data in a table format. 

These widgets are not directly interchangeable and using them together 
might not be straightforward.
```

### Question 3.4
The intention is to provide a backup/restore facility for a `QListWidget` class such as
the `model` given in 3.2. Write the class definition (which would be found in the header
file) of a `QListWidget` or similar class that would make this backup/restore possible
using a common design pattern. Explain clearly all code provided in this class. (4 marks)

#### 3.4 - Answer:
```c++
class ListWidgetMemento
{
private:
	friend class ListWidgetList; // Declare Originator friend
	ListWidgetMemento(); // Constructor for the memento
	QListWidget getState(); // A function to return the state of type QListWidget
	void setState(QListWidget listWidget); // A function to set the state of a listWidget
	QListWidget listWidgetList; // Add list to store state
};
```

### Question 3.5
Suppose that there is a `WriteCodeList` class that will be used to send the code list
over a network. This class should be run as a thread, and the following code is provided.
```c++
// pass the model (containing the code list) to the constructor
WriteCodeList *writer(new WriteCodeList(model));
QThread t(new QThread());
writer->moveToThread(t);
connect(t, SIGNAL(started()), writer, SLOT(writeList()));
t->start();
```


### Question 3.5.1
Provide the class declaration (that would be found in the header file) for the
`WriteCodeList` class. (6 marks)

#### 3.5.1 - Answer:
```c++
class WriteCodeList : public QObject  // Must inherit from QObject to use thread functionality
{
    Q_OBJECT  // Must inherit from QObject to use thread functionality
    
public:
    WriteCodeList(QListWidget model);
    
public slots:
    writeList();
}

```

### Question 3.5.2
How can you ensure that all memory allocated will be properly cleaned up after the
thread has completed its work? You may describe this in detail or provide the necessary
code (showing clearly where this code would be located). (6 marks)

```text
Description:
- In order to ensure that all memory allocated will be properly cleanup up after the thread has 
  completed its work, you would need to:
    - Connect the WriteCodeList's 'finished' signal to the thread's 'quit' slot.
    - Connect the WriteCodeList's 'finished' signal to the WriteCodeList's 'deleteLater' slot.
    - Connect the WriteCodeList's 'finished' signal to the thread's 'deleteLater' slot.
```

```c++
QObject::connect(writer, SIGNAL(finished()), thread, SLOT(quit()));         // Connect writer's 'finished' signal to the thread's 'quit' slot
QObject::connect(writer, SIGNAL(finished()), writer, SLOT(deleteLater()));  // Connect writer's 'finished' signal to the writer's 'deleteLater' slot
QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));  // Connect writer's 'finished' signal to the thread's 'deleteLater' slot
```

### Question 3.5.3
Which design pattern would this cleaning up in response the completion of a task (from
3.5.2) be an example of (as the cleanup would be implemented here)? (1 mark)

#### 3.5.3 - Answer
```text
The design pattern illustrated here is an example of the Observer Pattern.

The thread object (subject) emits the finished signal, and the connected slot(s) (observers) 
respond to this signal by performing cleanup actions. This helps in achieving a decoupled design 
where the thread and cleanup logic are separate, making the code more modular and maintainable.
```

### Question 3.6
Apart from the persistence factor, what is the major difference between using a Memento
and Serializer design pattern? (1 mark)

#### 3.6
```text
Memento Design Pattern:
Purpose: 
- The Memento pattern is primarily concerned with capturing and externalizing an object's 
  internal state so that it can be restored to this state later.

Scope:
- It focuses on providing the ability to capture and restore the state of an 
  individual object, often for the purpose of implementing undo/redo mechanisms or 
  managing the history of an object's state changes.


Serializer Design Pattern:
Purpose: 
- The Serializer pattern is more general and is concerned with converting complex data 
  structures or objects into a format that can be easily stored, transmitted, or reconstructed.

Scope: 
- It encompasses a broader range of functionalities, including serialization for 
  persistence, data exchange between different systems, or communication across a network. 
- Serialization involves converting an object's state to a format that can be later 
  reconstructed, and deserialization is the reverse process.

In summary, while both patterns involve the handling of object states, the Memento pattern is 
specialized for managing an object's state for purposes like undo/redo, whereas the Serializer 
pattern is a more general pattern for converting object states into a format suitable for various 
purposes, including persistence.
```

## Question 4
The plan is to create a list of pallets. There should only be one such list. The following class is
proposed as the way to implement this list (assuming that `Pallet` is a class that holds
containers).
```c++
class ListOfPallets
{
public:
    ListOfPallets();
    static ListOfPallets *listOfPallets();
private:
    static ListOfPallets *list;
    QList<Pallet> pallets;
};
```

### Question 4.1
Which design pattern would be required here? (1 mark)

#### 4.1 - Answer
```text
Singleton pattern
```

### Question 4.2
Is this class definition being correctly implemented for this design pattern? If yes, state
why you say so; if not, correct the code. (1 mark)

#### 4.2 - Answer
```text
No, the constructor of a singleton class must be private.
```

```c++
class ListOfPallets
{
public:
    static ListOfPallets *listOfPallets();
private:
    ListOfPallets();
    static ListOfPallets *list;
    QList<Pallet> pallets;
};
```

### Question 4.3
Write the code to demonstrate how you obtain an instance of the `ListOfPallets` in
the correct implementation of this design pattern. (2 marks)

#### 4.3 - Answer
```c++

ListOfPallets *ListOfPallets::list = nullptr;

ListOfPallets *ListOfPallets::listOfPallets()
{
    if(list == nullptr)
    {
        list = new ListOfPallets();
    }

    return list;
}
```

### Question 4.4
Why would the function `listOfPallets`() be `static` in the correct implementation
of the design pattern that should be used here? (2 marks)

```text
In the context of a Singleton pattern, the function that returns the static instance of the 
singleton class is typically made static for a few important reasons:

1. Access Without Instance:
- The purpose of a Singleton pattern is to ensure that only one instance of the class is created, and 
  that instance is globally accessible. By making the function static, it allows access to the 
  singleton instance without needing to create an object of the class. This is crucial because 
  creating an object would defeat the purpose of having a single instance.

2. Global Accessibility:
- Making the function static enables global access to the singleton instance. Clients can access the 
  singleton without having to instantiate the class, making it convenient and consistent with the 
  concept of a global point of access.

3. Consistency in Usage:
- The use of a static function promotes consistency in how clients interact with the singleton class. 
  Clients always call the same static function to obtain the singleton instance, regardless of 
  whether they have an object instance or not.

4. Preventing Unintended Instantiation:
- By making the function static, you prevent accidental instantiation of the class. The Singleton 
  pattern dictates that the instantiation should be controlled, ensuring only one instance is created. 
  A static function enforces this control by making sure clients access the instance through a 
  controlled point.
```