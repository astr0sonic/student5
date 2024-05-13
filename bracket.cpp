#include "bracket.h"
#include <stack>
#include <string>
using namespace std;

bool checkBrackets(const std::string& s) {
    stack<char> brackets;

    for (char bracket : s)
    {
        if (bracket == '(' || bracket == '[' || bracket == '{' || bracket == '<') 
        {
            brackets.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}' || bracket == '>')
        {
            if (brackets.empty()) 
            {
                return false;
            }
            else if ((bracket == ')' && brackets.top() == '(') || (bracket == ']' && brackets.top() == '[') || (bracket == '}' && brackets.top() == '{') || (bracket == '>' && brackets.top() == '<'))
            {
                brackets.pop();
            }
            else 
            {
                return false;
            }
        }
    }
    return brackets.empty();
}