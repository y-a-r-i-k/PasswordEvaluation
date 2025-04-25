#include "checker.h"
#include "iso646.h"

Checker::Checker()
{

}

bool Checker::isSpecialSymbol(char c) {
    if (c=='/' or c=='(' or c==')' or c=='[' or c==']' or c=='{' or c=='}' or c=='@' or c=='#' or c=='$' or c=='%' or c=='^' or c=='&' or c=='*' or c=='?' or c == '+' or c=='-') {
        return true;
    }
}

bool Checker::isPoints(char c) {
    if (c=='.' or c==':' or c==';' or c==',') {
        return true;
    }
}


