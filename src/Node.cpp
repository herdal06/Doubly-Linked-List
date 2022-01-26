
#include "Node.hpp"

Node::Node() { // bos kurucu fonksiyon
    this->data = 0;
    next = NULL;
    prev = NULL;
}
Node::Node(const int& data) { // parametre olarak data alan kurucu fonksiyon
    this->data = data;
    next = NULL;
    prev = NULL;
}
Node::Node(const int& data = 0, Node* next = NULL, Node* prev = NULL) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}