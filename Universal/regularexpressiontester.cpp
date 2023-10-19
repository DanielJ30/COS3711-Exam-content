
#include "regularexpressiontester.h"

RegularExpressionTester::RegularExpressionTester(QString reg)
{
    regex.setPattern(reg);
}

void RegularExpressionTester::setRegexPattern(QString reg)
{
    regex.setPattern(reg);
}

void RegularExpressionTester::testExpression(QString expression)
{
    if(regex.match(expression).hasMatch())
        qDebug() << "The expression: " << expression << " WAS a match to the regular expression: " << regex.pattern();
    else
        qDebug() << "The expression: " << expression << " WAS NOT a match to the regular expression: " << regex.pattern();
}

RegularExpressionTester::RegularExpressionTester()
{
    //No pattern has been set
}

