#include "calculator.h"

double calculate(const std::string& expr) {
    stack<string> stack_postfix;
    stack <string> reverse_postfix;
    get_postfix(expr, &stack_postfix);
    reverse_stack(stack_postfix, &reverse_postfix);
    double result = calculate_postfix(reverse_postfix);
    return result;
}

void get_postfix(const string& expr, stack<string>* postfix)
{
    stack<char> operators;
    int index = 0, open_brackets_count = 0;
    for (char sym : expr)
    {
        if (isspace(sym))
        {
            index++;
            continue;
        }
        if (isdigit(sym) || sym == '.')
        {
            string digit = "";
            while (index < expr.size() && (isdigit(expr[index]) || expr[index] == '.'))
            {
                digit += expr[index++];
            }
            index--;
            postfix->push(digit);
        }
        else if (sym == '(')
        {
            operators.push(sym);
            open_brackets_count++;
        }
        else if (sym == ')')
        {
            while (operators.top() != '(')
            {
                postfix->push(string(1, operators.top()));
                operators.pop();
            }
            open_brackets_count--;
            operators.pop();
        }
        else if (is_oper(sym))
        {
            if (sym == '-' && (index == 0 || expr[index - 1] == '('))
            {
                operators.push('~');
            }
            else
            {
                while (!operators.empty() && get_priority_oper(operators.top()) >= get_priority_oper(sym))
                {
                    postfix->push(string(1, operators.top()));
                    operators.pop();
                }
                operators.push(sym);
            }
        }
        else
        {
            throw runtime_error("invalid");
        }
        index++;
    }
    if (open_brackets_count > 0)
    {
        throw runtime_error("invalid");
    }
    while (!operators.empty())
    {
        postfix->push(string(1, operators.top()));
        operators.pop();
    }
}

bool is_oper(char sym)
{
    return (sym == '+' || sym == '-' || sym == '*' || sym == '/' || sym == '^' || sym == '~');
}

int get_priority_oper(char sym)
{
    int priority_oper = -1;
    switch (sym)
    {
    case '(':
        priority_oper = OPEN_BRACKET;
        break;
    case ')':
        priority_oper = CLOSED_BRACKET;
        break;
    case '+':
    case '-':
        priority_oper = PLUS_OR_MINUS;
        break;
    case '*':
    case '/':
        priority_oper = MULT_OR_DIV;
        break;
    case '^':
        priority_oper = DEGREE;
        break;
    default:
        priority_oper = UNARY_MINUS;
        break;
    }
    return priority_oper;
}

void reverse_stack(stack<string> postfix, stack<string>* reverse_postfix)
{
    while (!postfix.empty())
    {
        reverse_postfix->push(postfix.top());
        postfix.pop();
    }
}

double calculate_postfix(stack<string> postfix)
{
    stack<double> stackP;
    while (!postfix.empty())
    {
        string sym = postfix.top();
        postfix.pop();
        while (!isalnum(sym[0]) && !is_oper(sym[0]))
        {
            sym = postfix.top();
            postfix.pop();
        }
        double oper = 0.0;
        if (isdigit(sym[0]))
        {
            oper = stod(sym);
            stackP.push(oper);
        }
        else if (is_oper(sym[0]))
        {
            if (sym[0] == '~')
            {
                double temp = stackP.top();
                stackP.pop();
                temp = -temp;
                stackP.push(temp);
            }
            else
            {
                if (stackP.size() < 2)
                {
                    throw runtime_error("not enough operands for operation");
                }
                double first_num = stackP.top();
                stackP.pop();
                double second_num = stackP.top();
                stackP.pop();
                double result_oper = get_expression_val(second_num, first_num, sym);
                stackP.push(result_oper);
            }
        }
    }
    if (stackP.size() != 1)
    {
        throw runtime_error("invalid expr: more than one val left in stack");
    }
    return stackP.top();
}

double get_expression_val(double first_num, double second_num, string operators)
{
    double result = 0.0;
    if (operators == "+")
    {
        result = first_num + second_num;
    }
    else if (operators == "-")
    {
        result = first_num - second_num;
    }
    else if (operators == "*")
    {
        result = first_num * second_num;
    }
    else if (operators == "/")
    {
        if (second_num == 0.0)
        {
            throw runtime_error("div by zero");
        }
        else
        {
            result = first_num / second_num;
        }
    }
    else if (operators == "^")
    {
        result = pow(first_num, second_num);
    }
    return result;
}