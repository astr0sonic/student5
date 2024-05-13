#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
#include <stdexcept>
using namespace std;

const int OPEN_BRACKET = 0;
const int CLOSED_BRACKET = 1;
const int PLUS_OR_MINUS = 2;
const int MULT_OR_DIV = 3;
const int DEGREE = 4;
const int UNARY_MINUS = 5;

double calculate(const std::string& expr);
void get_postfix(const string& expr, stack<string>* postfix);
bool is_oper(char sym);
int get_priority_oper(char sym);
void reverse_stack(stack<string> postfix, stack<string>* reverse_postfix);
double calculate_postfix(stack<string> postfix);
double get_expression_val(double first_num, double second_num, string operators);