# January-February 2021

---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.

---

## Case:
Government and state authorities produce many different kinds of documents. The questions
in this paper are based on a simplified scenario for keeping a register of such documents.

Suppose that there are three types of documents that are produced: regulations (which have
an Act number as they are published as acts of the relevant parliament), policies (which are
issued by a particular department), and guidelines (which are formulated for a particular topic).
All documents have a number and status.

## Question 1
The following UML class diagram has been produced as an initial attempt at modelling this
scenario.

![Jan-Feb-2021-Q1_Figure_1.jpg](..%2FResources%2FJan-Feb-2021-Q1_Figure_1.jpg)

The follow design decisions have been made:
- A classic Factory Method design pattern should be used.
- Base classes that have derived classes should be abstract.

### Question 1.1:
Considering the scenario given and design decisions listed above, redesign the UML
class diagram provided. You should include the necessary classes, class attributes,
class constructors and operations, and class relationships to make it clear you
understand how data will be managed and passed between classes. All elements in the
provided UML class diagram above should be included in your design (although some
of them may have to be adjusted). You do not have to include the Client/GUI class.
[If you are hand drawing this answer, you can use an underline to indicate italics in the
UML class diagram.] (15 marks)

#### 1.1 - Answer
![Jan-Feb-2021-Q1.1.jpg](..%2FResources%2FJan-Feb-2021-Q1.1.jpg)

### Question 1.2:
Which anti-pattern could be identified in the original design? Explain clearly why you say
so. (2 marks)

#### 1.2 - Answer:

```text
The Blob
- Procedural-style design leads to one object with a lion’s share of the responsibilities, 
  while most other objects only hold data or execute simple processes. 
  The solution includes refactoring the design to distribute responsibilities more uniformly 
  and isolating the effect of changes.
```

### Question 1.3:
Write the implementation code (that you would expect to find in the `.cpp` file) for the
function that would be used in your factory method class to create the various
documents. All the data necessary to create the required objects should be passed to
this function. (7 marks)
---

#### 1.3 - Answer
```c++
Document* DocumentFactory::createDocument(QString type, QString number, QString status, QString data)
{
    if (type == "regulation")
    {
        return new Regulation(data);
    }
    else if (type == "policy")
    {
        return new Policy(data);
    }
    else if (type == "guideline")
    {
        return new Guideline(data);
    }
}
```

## Question 2
It has been decided to use a model-view approach to hold a register of all documents. The
following code is offered as an initial attempt at the model part of the solution – read through
the code carefully to see what approach has been proposed. Some code still needs to be
provided.
This question is based on a corrected design presented in question 1.

```c++
// class header
class MyModel : public QStandardItemModel
{
public:
    static MyModel* MyModel();
    bool addDocument(Document* d); // to add a Document to the model
    QList<Document*> getModelData() const; // return data for writing to file
private:
    bool checkDocumentNumber(QString n); // a check function
};

// implementation detail
// constructor sets up model header row
MyModel::MyModel()
{
    QStringList headerRow;
    headerRow.append("Number");
    headerRow.append("Status");
    headerRow.append("Topic");
    headerRow.append("Department");
    headerRow.append("Act");
    setHorizontalHeaderLabels(headerRow);
}
// this function is called by addDocument() to ensure that the document
// number meets certain requirements
bool MyModel::checkDocumentNumber(QString n)
{
    // code needs to be provided here; see questions below
}
// this function is used to add a document to the model
// it uses meta-objects to find document type and properties
// after checking that the number is in the correct format
// data is added to the appropriate cells in the model
bool MyModel::addDocument(Document* d)
{
    // use the meta-object to find out what type of document d is
    QString num = // use the meta-object to find the document number
    if (!checkDocumentNumber(num)) // this code checks that num is valid
    return false;
    // add the data items to the model
    // based on what type of document it is
    // use the meta-object to access all the data in the object
    // you need only handle the case where the document is a policy
    // you may assume that all other document types are already coded
    return true;
}

QList<Document*> MyModel::getModelData() const
{
    // you may assume that this has been implemented
    // it returns a QList of Document pointers from model data
}
```

Below is an example of a view of the model.
![Jan-Feb-2021-Q2_Figure_1.jpg](..%2FResources%2FJan-Feb-2021-Q2_Figure_1.jpg)

### Question 2.1:
The class was supposed to be implemented following the classic Singleton design
pattern. However, it is not working correctly.
Rewrite the class header as part of fixing the problems. (5 marks)

#### 2.1 - Answer:
```c++
class MyModel : public QStandardItemModel
{
public:
    static MyModel* MyModel();              // Public MyModel() method returns the only instance of the MyModel
                                            // Must be static
                                
    bool addDocument(Document* d);          // To add a Document to the model
    QList<Document*> getModelData() const;  // Return data for writing to file
private:
    MyModel();                              // Constructor is private (this is a standard in the singleton design pattern)
    static MyModel *instance;               // The static pointer to the only instance of MyModel
    bool checkDocumentNumber(QString n);    // A check function
};
```

### Question 2.2:
You need to code the `bool MyModel::checkDocumentNumber(QString n)` function,
which uses regular expressions to check that the document number meets a particular
format (in the order given below).
- The first 3 characters should be GDL, POL, or RGL (for guidelines, policies, and
regulations respectively).
- A slash.
- Exactly 3 arbitrary uppercase alphabetic characters.
- Another slash.
- A year value in the range from 1900 onwards.

Using a validator, check whether the `QString` passed to the function is acceptable.
Return `true` if it is, and `false` if not. (14 marks)

#### 2.2 - Answer:
```c++
bool MyModel::checkDocumentNumber(QString n)
{
    QRegularExpression re("(?:GDL|POL|RGL)\\/[A-Z]{3}\\/(?:18|19|20|21)[0-9]{2}");
    QRegularExpressionMatch match(re.match(n));

    if (match.hasMatch()) {
        return true;
    } 
    else 
    {
        return false;    
    }
}
```

### Question 2.3:
The code for `bool MyModel::addDocument(Document* d)` function is incomplete. You
need to add code as indicated above so that meets the following design criteria.
- It should use meta-objects to access the data in the `Document` objects. You may
assume that all objects support meta-objects.
- It should add the data from the `Document` object to the model. You need only handle
the case of Policy documents.

You only need to write code for
- accessing the object data via the meta-object, and
- adding data for a policy document to the model.

You may assume that there is code for adding the other two types of documents.
You may find it helpful to check the image of the model’s view above. (12 marks)

#### 2.3 - Answer:
```c++
// this function is used to add a document to the model
// it uses meta-objects to find document type and properties
// after checking that the number is in the correct format
// data is added to the appropriate cells in the model
bool MyModel::addDocument(Document* d)
{
    // use the meta-object to find out what type of document d is
    const QMetaObject *metaObject = d->metaObject();    // Get the metaObject for the provided document pointer named d
    QString num = (metaObject->property(metaObject->indexOfProperty("number"))).read(d).toString(); // Get the number of the document
    
    if (!checkDocumentNumber(num)) // this code checks that num is valid
    {
        return false;
    } 
    
    // add the data items to the model
    // based on what type of document it is
    // use the meta-object to access all the data in the object
    // you need only handle the case where the document is a policy
    // you may assume that all other document types are already coded
    
    MyModel* myModel = MyModel(); // Get the singleton instance of MyModel
    QString status = (metaObject->property(metaObject->indexOfProperty("status"))).read(d).toString(); // Get the status of the document
    QString department = (metaObject->property(metaObject->indexOfProperty("department"))).read(d).toString(); // Get the department of the document
    
    int rowCount = myModel.rowCount();  // Get the rowCount of myModel
    
    QStandardItem *numItem = new QStandardItem(num);                // Create a QStandardItem for num
    QStandardItem *statusItem = new QStandardItem(status);          // Create a QStandardItem for status
    QStandardItem *departmentItem = new QStandardItem(department);  // Create a QStandardItem for department
    
    myModel.setItem(rowCount, 0, numItem);         // Add number item in row 'rowCount', column 0 
    myModel.setItem(rowCount, 1, statusItem);      // Add status item in row 'rowCount', column 1
    myModel.setItem(rowCount, 3, departmentItem);  // Add department item in row 'rowCount', column 3
    
    return true;
}
```

### Question 2.4:
Which view class would you use to display the data in this model? (1 mark)

#### 2.4 - Answer:
```text
QTableView
```

## Question 3:
The model will be saved as an XML file when the application closes, and then read in again
when the application opens. The following class has been designed to achieve this.

```c++
class ReadWriteXml
{
public:
    ReadWriteXml();
    void WriteXml(QList<Document*>);
    void ReadXml();
private:
    QDomDocument XMLdoc;
};
```

The XML file that is used is in the following format. You may assume that the tags will always
be in the order in which they appear here.

```xml
<documents>
    <document class="Guideline" number="GDL/AAA/2020">
        <status>S</status>
        <topic>Wearing masks</topic>
    </document>
    <document class="Regulation" number="RGL/CCC/1994">
        <status>S</status>
        <act>3 of 1994</act>
    </document>
    <document class="Policy" number="POL/EEE/2021">
        <status>P</status>
        <department>DBE</department>
    </document>
</documents>
```

### Question 3.1:
Which design pattern is being employed here? (1 mark)

#### 3.1 - Answer:
```text
Serializer design pattern
```

### Question 3.2:
Has this design pattern been implemented correctly? Explain clearly why you say so. (2 marks)

#### 3.2 - Answer:
```text
Yes, it supports both the read and write aspects of the serializer pattern.
```

### Question 3.3:
The partial code for the `ReadXml()` function that reads the XML file, recreates `Document`
objects, and adds them to the model is provided below. You should use the code
provided for the `MyModel` class in Question 2 as reference. Note that not all the
necessary code is provided, and there are parts that you are not required to supply (it is
printed in italics).

```c++
void ReadWriteXml::ReadXml()
{
    // open file and read all contents into a QDomDocument
    QFile file("documents.xml");
    file.open(QIODevice::ReadOnly);
    XMLdoc.setContent(&file);
    file.close();
    // parse the QDomDocument
    QDomElement root = XMLdoc.documentElement();
    if(root.tagName() == "documents")
    {
        QDomNode node = root.firstChild();
        while(!node.isNull())
        {
            QDomElement element = node.toElement();
            if(element.tagName() == "document")
            {
                // enter code here to access the data needed to construct
                // a Document object:
                // QString classname
                // QString number
                // QString status
                // QString otherData
                
                // *the factory method will be used to create Document* d*
                // *from the data accessed above*
                // *you do NOT need to add this code*
                
                // add the created Document d to the model
                MyModel::getInstance()->addDocument(d);
            }
            node = node.nextSibling();
        }
    }
}
```
