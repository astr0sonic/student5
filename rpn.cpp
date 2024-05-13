#include "rpn.h"
#include <stack>
#include <sstream>
#include <string>
using namespace std;

double calculateRPN(const std::string& expr) {
    stack<double> stack;
    istringstream iss(expr);
    string token;
    while (iss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            double b = stack.top();
            stack.pop();
            double a = stack.top();
            stack.pop();
            if (token == "+")
            {
                stack.push(a + b);
            }
            else if (token == "-")
            {
                stack.push(a - b);
            }
            else if (token == "*")
            {
                stack.push(a * b);
            }
            else if (token == "/")
            {
                stack.push(a / b);
            }
        }
        else
        {
            stack.push(std::stod(token));
        }
    }
    return std::round(stack.top() * 1000) / 1000;
}