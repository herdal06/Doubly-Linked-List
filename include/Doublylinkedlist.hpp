#ifndef DOUBLYLINKEDLIST_HPP
#define DOUBLYLINKEDLIST_HPP
#include "Node.hpp"

class Doublylinkedlist {
private:
    int size;
    Node* head;
    Node* tail;
public:
    Doublylinkedlist();
    bool IsEmpty();
    void arrayToList(int*, int);
    void print();
    void push(int);
    Node* reverseList();
    void swapNodes(Node*,Node*);
    void compareNodes(Doublylinkedlist*,Doublylinkedlist*);
    void pop_back();
    ~Doublylinkedlist();
};

#endif