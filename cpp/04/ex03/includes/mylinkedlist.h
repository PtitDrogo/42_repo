#pragma once
#include <iostream>

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int d) : data(d), next(NULL) {}
    };

    Node *head;

public:
    LinkedList() : head(NULL) {}

    ~LinkedList()
    {
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
};