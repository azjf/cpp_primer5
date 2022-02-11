#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

double evaluate(std::vector<std::string> &expr)
{
    std::stack<std::string> ops;
    std::stack<double> vals;
    for (const auto &s : expr) {
        if (s == "(") {
        } else if (s == "+" || s == "-" || s == "*" || s == "/" || s == "sqrt") {
            ops.push(s);
        } else if (s == ")") {
            std::string op = ops.top();
            ops.pop();
            double v = vals.top();
            vals.pop();
            if (op == "+") {
                v = vals.top() + v;
                vals.pop();
            } else if (op == "-") {
                v = vals.top() - v;
                vals.pop();
            } else if (op == "*") {
                v = vals.top() * v;
                vals.pop();
            } else if (op == "/") {
                v = vals.top() / v;
                vals.pop();
            } else if (op == "sqrt") {
                v = std::sqrt(v);
            }
            vals.push(v);
        } else {
            vals.push(std::stod(s));
        }
    }
    return vals.top();
}

int main()
{
    std::vector<std::string> expr{"(", "1", "+", "(", "(", "2", "+", "3", ")",
        "*", "(", "4", "*", "5", ")", ")", ")"};
    std::cout << evaluate(expr) << std::endl;

    expr = {"(", "(", "1", "+", "sqrt", "(", "5.0", ")", ")", "/", "2.0", ")"};
    std::cout << evaluate(expr) << std::endl;
    return 0;
}
