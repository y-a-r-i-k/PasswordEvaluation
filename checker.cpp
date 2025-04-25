#include "checker.h"
#include "iso646.h"

#include <QCharRef>

Checker::Checker()
{

}

bool Checker::isSpecialSymbol(QCharRef c) {
    if (c=='/' or c=='(' or c==')' or c=='[' or c==']' or c=='{' or c=='}' or c=='@' or c=='#' or c=='$' or c=='%' or c=='^' or c=='&' or c=='*' or c=='?' or c == '+' or c=='-') {
        return true;
    }
}

bool Checker::isPoints(QCharRef c) {
    if (c=='.' or c==':' or c==';' or c==',') {
        return true;
    }
}


