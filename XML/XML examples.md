# October-November 2022
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

# October-November 2021
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
