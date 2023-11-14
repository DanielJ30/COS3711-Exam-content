# January-February 2022

---
**Disclaimer**:
These resources are meant for learning purposes and comes with no guarantee of accuracy or correctness.
Please do your own research and use it as a tool to double-check your own work, attempts and understanding.

---

## Case:
Transporting cargo around the world is essential in ensuring that customers have access to the
goods they need and want.

All such items are packaged in some sort of container (which, for the purposes of this scenario,
has some volume). Generally, there are two kinds of containers: (i) a box (where we want to
know whether it is cube shaped or not), and (ii) a cylinder (where we want to know its diameter).

For transport, containers are packed onto pallets, and pallets are then included in a load (where
each load will have a code).

## Question 1
### Question 1.1:
Considering the scenario given above, draw a partial UML class diagram that captures
the scenario. You should include the necessary classes, class attributes, and class
relationships that are mentioned in the scenario. You do not have to include the
Client/GUI class nor indicate constructors, access specifiers, or other methods in the
classes you specify.
[You may use a software tool to create the UML class diagram.] (14)

#### 1.1 - Answer
![Jan-Feb-2022-Q1.1.jpg](..%2FResources%2FJan-Feb-2022-Q1.1.jpg)

### Question 1.2:
Would you use aggregation or composition relationships in the design of this UML class
diagram? Explain why you have or have not done so. (2)

#### 1.2 - Answer:
```text
I would use aggregation as a pallet can exist without containers, and a load can exist without pallets.
`Aggregation` represents a "has-a" relationship with a weaker connection, where parts can exist 
independently, while `Composition` represents a stronger "has-a" relationship with a lifecycle 
dependency, where the parts cannot exist without the whole.
```
### Question 1.3:
The load code takes the following format.
- Year value between 2000 and 2099 (both included)
- Forward slash (/)
- Month value between 01 and 12 (both included)
- Forward slash (/)
- L
- A serial number starting from 1, running up to 9999

Write the regular expression (in quotes) that can be used to check that a load code meets
the required criteria. An example of a valid code is 2022/01/L1. Ensure that you use
escape characters correctly. (8)

`Note: Do not use block brackets unnecessarily`
https://regex101.com/

#### 1.3 - Answer:
```c++
"^(200\\d|20[1-9]\\d)\\/(0[1-9]|1[0-2])\\/L[1-9]\\d{0,3}$"

or


"^(200[0-9]|20[1-9][0-9])\\/(0[1-9]|1[0-2])\\/L[1-9][0-9]{0,3}$"
```

