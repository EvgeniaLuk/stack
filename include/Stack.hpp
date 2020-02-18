// Copyright 2018 Your Name <your_email>

#pragma once

#include <iostream>
#include <type_traits>
#include <exception>

template <typename T>
class Stack
{
protected:
    struct Node {
        T data;
        Node *next;
    };
    Node *head;

public:
    Stack() = default;

    ~Stack() {
        while (head) {
            auto *act = head;
            head = act->next;
            delete act;
        }
    }

    void push(T&& value) {
        if (head == nullptr) {
            auto node = new Node{std::move(value), nullptr};
            head = node;
        } else {
            auto node = new Node{std::move(value), head};
            head = node;
        }
    }

    const T& Head() {
        if (!head)
            throw std::exception();
        return head->data;
    }
};
