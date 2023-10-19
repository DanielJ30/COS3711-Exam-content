
#ifndef XMLWRITER_H
#define XMLWRITER_H


#include <QObject>
#include <QtXml>
#include <QFile>
#include <QTextStream>
#include <QDebug>

//Included the property class for reading a property into xml
#include "metapropertyclass.h"

class XMLWriter: public QObject
{
    Q_OBJECT
public:
    XMLWriter();

    //Use this to write the xml to a file (Not using Q_PROPERTY)
    void WriteToFile();

    //Use this to write the xml to a file (Using Q_PROPERTY)
    void WritePropertiesToFile();
};

#endif // XMLWRITER_H
