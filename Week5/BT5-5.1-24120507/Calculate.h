#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

bool is_operator (char c) {
    return ((c == '+') || (c == '-') || (c == '*') || (c == '/'));
}

// Return the priority of the operator 
// multiplication and division first , then plus and minus
int priorize (char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

double calc (double a , double b , char op) {
    switch (op) {
        case '+' : return a + b;
        case '-' : return a - b;
        case '*' : return (long double) a * b;
        case '/' : 
            if (!b) throw std::invalid_argument ("Divided by zero");
            return a / b;
    }
    throw std::invalid_argument("Invalid operator");
}

template <class T>
T calc (std::string s , int type) {
    std::stack<T> value;
    std::stack<char> op;
    std::stringstream ss(s);
    char tmp;

    while (ss >> tmp) {
        // exponent mus be non-negative integer
        if (type && tmp == '.')
            throw std::invalid_argument("Invalid exponent");

        if (isdigit(tmp) || tmp == '.') {
            ss.putback(tmp);
            T val;
            ss >> val;
            value.push(val);
        }
        else if (tmp == '(') op.push(tmp);
        else if (tmp == ')') {
            while (op.size() && op.top() != '(') {
                // Take 2 first number at the top of the stack to do the operator
                T b = value.top();
                value.pop();
                T a = value.top();
                value.pop();
                
                //Then push the answer to the top of stack
                value.push(calc (a , b , op.top()));
                op.pop(); // delete the operator that used
            }
            
            // Delete '('
            if (op.size()) op.pop();
        }
        else if (is_operator (tmp)) {
            // Mul and Div first then plus and minus
            while (op.size() && priorize(op.top()) >= priorize(tmp)) {
                // Take 2 first number at the top of stack to do the operator
                T b = value.top();
                value.pop();
                T a = value.top();
                value.pop();

                // Then push the answer to the top of stack
                value.push(calc(a , b , op.top()));
                op.pop(); // Delete the operator that used
            }
            // Push the opeator to the top of stack
            op.push(tmp);
        }
    }

    // If still have the operator
    while (op.size()) {
        // Take 2 first number at the top of stack to do the operator
        T b = value.top();
        value.pop();
        T a = value.top();
        value.pop();

        // Then push the answer to the top of stack
        value.push(calc(a , b , op.top()));
        op.pop(); // Delete the operator that used
    }
    // Return the answer that is the top of stack
    return value.top();
}