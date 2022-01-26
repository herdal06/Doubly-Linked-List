#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node();
    Node(const int&);
    Node(const int&, Node*, Node*);
};

#endif