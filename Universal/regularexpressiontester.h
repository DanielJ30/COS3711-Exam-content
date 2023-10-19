
#ifndef REGULAREXPRESSIONTESTER_H
#define REGULAREXPRESSIONTESTER_H


#include <QObject>
#include <QRegularExpression>
#include <QValidator>
#include <QDebug>

class RegularExpressionTester: public QObject
{
    Q_OBJECT
public:
    //deafult constructor
    RegularExpressionTester();

    //sets the regular expression
    RegularExpressionTester(QString reg);

    //set the regular expression
    void setRegexPattern(QString reg);

    void testExpression(QString expression);

private:
    QRegularExpression regex;
};

#endif // REGULAREXPRESSIONTESTER_H
