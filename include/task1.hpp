// Copyright 2018 Your Name <your_email>
#ifndef TASK1_HPP_INCLUDED
#define TASK1_HPP_INCLUDED
#pragma once

#include "Stack.hpp"

template <class T>
class F_Stack : public Stack<T>
{
public:
    void push(const T& value) {
        auto node = new typename Stack<T>::Node{value, Stack<T>::head};
        Stack<T>::head = node;
    }

    void pop() {
        if (Stack<T>::head)
            Stack<T>::head = Stack<T>::head->next;
        else
            throw std::exception();
    }
};


#endif // TASK1_HPP_INCLUDED
