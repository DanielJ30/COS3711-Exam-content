
#include "metapropertyclass.h"

MetaPropertyClass::MetaPropertyClass()
{
    //No properties gte set, must use the meta object propertues to set them
}

MetaPropertyClass::MetaPropertyClass(QVariant prop1, QVariant prop2, QVariant prop3)
{
    //properties have been set, can use meta object to read them
    property1 = prop1;
    property2 = prop2;
    property3 = prop3;
}

QVariant MetaPropertyClass::getProperty1()
{
    return property1;
}

QVariant MetaPropertyClass::getProperty2()
{
    return property2;
}

QVariant MetaPropertyClass::getProperty3()
{
    return property3;
}

void MetaPropertyClass::setProperty1(QVariant value)
{
    property1 = value;
}

void MetaPropertyClass::setProperty2(QVariant value)
{
    property2 = value;
}

void MetaPropertyClass::setProperty3(QVariant value)
{
    property3 = value;
}
