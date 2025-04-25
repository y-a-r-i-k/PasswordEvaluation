#ifndef CHECKER_H
#define CHECKER_H

#include <QCharRef>


class Checker
{
public:
    Checker();
    bool isSpecialSymbol(QCharRef c);
    bool isPoints(QCharRef c);
};

#endif // CHECKER_H
