/*
** EPITECH PROJECT, 2025
** Stack.hpp
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stack>
#include <stdexcept>
#include <string>

class Stack {
public:
    class Error : public std::exception {
    private:
        std::string message;
    public:
        Error(const std::string& msg) : message(msg) {}
        const char* what() const noexcept override
        {
            return message.c_str();
        }
    };

private:
    std::stack<double> stack;

public:
    void push(double value)
    {
        stack.push(value);
    }

    double pop()
    {
        if (stack.empty())
            throw Error("Empty stack");
        double value = stack.top();
        stack.pop();
        return value;
    }

    double top() const
    {
        if (stack.empty())
            throw Error("Empty stack");
        return stack.top();
    }

    void add()
    {
        if (stack.size() < 2)
            throw Error("Not enough operands");
        double a = pop();
        double b = pop();
        push(a + b);
    }

    void sub()
    {
        if (stack.size() < 2)
            throw Error("Not enough operands");
        double a = pop();
        double b = pop();
        push(b - a);
    }

    void mul()
    {
        if (stack.size() < 2)
            throw Error("Not enough operands");
        double a = pop();
        double b = pop();
        push(a * b);
    }

    void div()
    {
        if (stack.size() < 2)
            throw Error("Not enough operands");
        double a = pop();
        double b = pop();
        if (a == 0) {
            push(b);
            push(a);
            throw Error("Division by zero");
        }
        push(b / a);
    }
};

#endif /* !STACK_HPP_ */
