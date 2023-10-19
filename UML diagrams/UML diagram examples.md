
---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.
---

# JanFeb 2023

## Case:
There are many who make the argument that climate change is going to affect weather patterns, and, thus, the amount of rainfall that is going to fall. Some may get more, while others will get less. Tracking rainfall is, therefore, an important task.
For the sake of this scenario, you may assume the following about designing an application that tracks rainfall.
- Rain data is stored using 3 pieces of data: the station that recorded the rainfall, the date for which the rainfall is recorded, and the amount of rain in mm.
- Obviously, there must be some way of recording all this data in a container.
- There should be a way of graphing the data. Initially, only a bar graph and a column graph are required. The data that is passed to the graphing application is an XML representation of the container holding all the rainfall data.
- Clearly, then, there needs to be some way of getting an XML representation of the rain record.
- The main client will be responsible for holding the record of all the rainfall data, for getting the XML representation of all the rainfall data, and for passing this to the user’s choice of graph.
- Appropriate design patterns should be used as necessary.

## Question 1
### Question 1.1:
Considering the scenario given above, draw a partial UML class diagram that captures
the scenario. You should include the necessary classes, class attributes, and class
relationships that are mentioned in the scenario. Class constructors and member access
specifiers are not required. However, you should ensure that you include all the data
members and member functions that show how data will be moved around the
application. You should include the Client/GUI class.
[You may use a software tool to create the UML class diagram. Use underlining to
represent italics in hand-drawn UML class diagrams.] (20 marks)

### Question 1.1 (20 marks): UML Class Diagram

Given that we cannot generate images here, let's use a tree view to represent the UML class diagram.

```
1. Rain
    Properties:
    - station: QString
    - date: QDate
    - mm: int

2. RainRecord
    Properties:
    - record: QList<Rain>

3.1. Graph
    Properties:
    # xmlString: QString
    
    Methods:
    + Graph(QString xml) | Graph()
    + graph(): void | graph(QString xml): void

3.2. Bar (derived from Graph)
    Methods:
    + Bar(QString xml)
    + graph(): void
    
3.3. Column (derived from Graph)
    Methods:
    + Column(QString xml)
    + graph(): void

4. Client
    Properties:
    - record: RainRecord
    - graph: Graph
    
5. RainRecordXML
    Methods:
    - writeToXML(RainRecord): QString
```

Relationships:
- `Bar` Inherits `Graph`
- `Column` Inherits `Graph`
- `Graph` Aggregates (Aggregation) `Client`
- `Rain` Aggregates (Aggregation) `RainRecord`
- `RainRecord` Aggregates (Aggregation) `Client`
- `Client` creates `Bar`
- `Client` creates `Column`
- `Client` uses `RainRecordXML`
- `RainRecordXML` uses `RainRecord`

![Jan-Feb-2023 Diagram.PNG](..%2FResources%2FJan-Feb-2023%20Diagram.PNG)

---
# Oct-Nov 2022

## Case:
Most people like chocolate. “Chocolate is a food made from roasted and ground cacao seed kernels, that is available as a liquid, solid or paste, on its own or as a flavouring agent in other foods” (https://en.wikipedia.org/wiki/Chocolate). Also, as most dark chocolates are vegan, they can be enjoyed by people with stricter dietary choices. Chocolate can also be found in many forms: bars, slabs, and in drinks, to name just a few.
For the sake of this scenario, you may assume the following about designing an application that manages various types of chocolate.
- Initially it has been decided that chocolates can come in bars and slabs. A user should not be able to create instances of a basic chocolate that is neither a bar nor a slab.
- All chocolates have a name (in the form of a string) and a flag indicating whether it is vegan or not. They should also all have a string representation of their data members.
- You are required to include the number of blocks there are for a slab chocolate.
- Each instantiated chocolate should have a unique serial number, starting at 1 and incrementing by 1 for each new chocolate instantiated. This should not be managed outside the chocolate class hierarchy.
- There is a register of chocolates that holds all instantiated chocolate objects.
- An appropriate design pattern should be used that allows the user to choose the kind of chocolate to instantiate.

## Question 1 [14 marks]
Considering the scenario given above, draw a partial UML class diagram that captures
the scenario. You should include the necessary classes, class attributes, and class
relationships that are mentioned in the scenario, including class member access
specifiers (+, -, #). `You do not have to include the Client/GUI class nor indicate
constructors or other methods in the classes you specify.`
[You may use a software tool to create the UML class diagram. Use underlining to
represent italics in hand-drawn UML class diagrams.] (14)

### Preparation - Draw up this table and assign classes, relationships, methods and properties
![Oct-Nov-2022 Q1.1 Diagram_Prep.jpg](..%2FResources%2FOct-Nov-2022%20Q1.1%20Diagram_Prep.jpg)

### Draw the UML diagram
![Oct-Nov-2022 Q1.1 Diagram.png](..%2FResources%2FOct-Nov-2022%20Q1.1%20Diagram.png)
---
# Oct-Nov 2021

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