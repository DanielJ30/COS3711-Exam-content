
#include "xmlwriter.h"

XMLWriter::XMLWriter()
{

}

void XMLWriter::WriteToFile()
{
    /*
    //This function is used to write to xml format that then gets saved to a file of type xml

    //----create the document----//
    QDomDocument doc;

    //----create the root----//
    QDomElement root(doc.createElement("RootElement"));

    //----append to the root----//
    doc.appendChild(root);

    //----loop through to get each element to add to the document----//
    for(int i = 0; i < 10; i++)
    {
        //----create element----//
        QDomElement element1(doc.createElement("Element_1_Name"));
        element1.setAttribute("AttributeName", "AttributeValue");

        //----append element to parent----//
        root.appendChild(element1);

        //----create element----//
        QDomElement element2(doc.createElement("Element_2_Name"));
        element2.setAttribute("AttributeName", "AttributeValue");

        //----append element to parent----//
        element1.appendChild(element2);

        //----create text node----//
        QDomText text(doc.createTextNode("TextValue"));
        element2.appendChild(text);
    }

    //----create the file----//
    QFile file("data1.xml");

    //----set to writeOnly----//
    file.open(QIODevice::WriteOnly);

    //----create a textStream----//
    QTextStream out(&file);

    //----append to the file----//
    out << doc.toString();

    //----close the file----//
    file.close();
*/

    //Add your code here:


}

void XMLWriter::WritePropertiesToFile()
{
    /*
    //This function is used to write a property to xml by accessing the classes properties via Q_PROPERTY

    //Create instances of the property class
    PropertyClass *prop1 = new PropertyClass("Value1", "Value2", "Value3");
    PropertyClass *prop2 = new PropertyClass();

    //Append to a list of type PropertyClass
    QList<PropertyClass*> propList;
    propList.append(prop1);
    propList.append(prop2);

    //----create the document----//
    QDomDocument doc;

    //----create the root----//
    QDomElement root(doc.createElement("RootElement"));

    //----append to the root----//
    doc.appendChild(root);

    //----get the meta object for each Property Class----//
    foreach(PropertyClass *propClass, propList)
    {
        //----meta object----//
        const QMetaObject *metaObj = propClass->metaObject();

        //----create a DomElement for the property----//
        QDomElement element(doc.createElement(metaObj->className()));
        root.appendChild(element);

        //----loop through all the properties of the meta object
        for (int i = metaObj->propertyOffset(); i < metaObj->propertyCount(); i++)
        {
            //----get the property at position i----//
            QMetaProperty metaProperty = metaObj->property(i);
            QString propName = metaProperty.name();
            QVariant propValue = metaProperty.read(propClass);

            //----create a child element----//
            QDomElement childElement(doc.createElement(propName));
            childElement.setAttribute(propName, propValue.toString());

            //----append to parent----//
            element.appendChild(childElement);
        }
    }

    //----create the file----//
    QFile file("data2.xml");

    //----set to writeOnly----//
    file.open(QIODevice::WriteOnly);

    //----create a textStream----//
    QTextStream out(&file);

    //----append to the file----//
    out << doc.toString();

    //----close the file----//
    file.close();

*/

    //Add your code here:

}

