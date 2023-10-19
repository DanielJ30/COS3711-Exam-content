
#ifndef METAPROPERTYCLASS_H
#define METAPROPERTYCLASS_H


#include <QObject>
#include <QVariant>
#include <QMetaProperty>
#include <QMetaObject>

class MetaPropertyClass: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant property1 READ getProperty1 WRITE setProperty1 CONSTANT);
    Q_PROPERTY(QVariant property2 READ getProperty2 WRITE setProperty2 CONSTANT);
    Q_PROPERTY(QVariant property3 READ getProperty3 WRITE setProperty3 CONSTANT);

public:
    //default constructor
    MetaPropertyClass();

    //constructor to set the properties
    MetaPropertyClass(QVariant prop1, QVariant prop2, QVariant prop3);

    //setters and getters
    QVariant getProperty1();
    QVariant getProperty2();
    QVariant getProperty3();

    void setProperty1(QVariant value);
    void setProperty2(QVariant value);
    void setProperty3(QVariant value);

private:
    QVariant property1;
    QVariant property2;
    QVariant property3;
};

#endif // METAPROPERTYCLASS_H
