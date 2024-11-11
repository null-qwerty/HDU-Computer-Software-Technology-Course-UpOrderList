#include <stdexcept>
#include <iostream>

#include "myList.hpp"

myList::myList()
{
    head = new Node;
    head->next = nullptr;
    length = 0;
}

myList::~myList()
{
    clear();
    delete head;
    std::cout << "[myList::~myList] delete list" << std::endl;
}

myList &myList::addend(int data)
{
    Node *p = head;
    while (p->next != nullptr) {
        p = p->next;
    }
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    p->next = newNode;
    length++;
    return *this;
}

myList &myList::del(int index)
{
    if (index <= 0 || index > length) {
        std::throw_with_nested(
            std::runtime_error("[myList::del] Index out of range"));
        return *this;
    }
    Node *p = getNode(index);
    Node *q = getNode(index - 1);
    q->next = p->next;
    delete p;
    length--;
    return *this;
}

myList &myList::insert(int index, int data)
{
    if (index <= 0 || index > length + 1) {
        std::throw_with_nested(
            std::runtime_error("[myList::insert] Index out of range"));
        return *this;
    }
    Node *p = getNode(index - 1);
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = p->next;
    p->next = newNode;
    length++;
    return *this;
}

myList &myList::replace(int index, int data)
{
    if (index <= 0 || index > length) {
        std::throw_with_nested(
            std::runtime_error("[myList::replace] Index out of range"));
        return *this;
    }
    Node *p = getNode(index);
    p->data = data;
    return *this;
}

int myList::lenth()
{
    return length;
}

int myList::get(int index)
{
    if (index <= 0 || index > length) {
        std::throw_with_nested(
            std::runtime_error("[myList::get] Index out of range"));
        return -1;
    }
    Node *p = getNode(index);
    return p->data;
}

myList &myList::clear()
{
    Node *p = head->next;
    while (p != nullptr) {
        Node *q = p->next;
        delete p;
        p = q;
    }
    head->next = nullptr;
    length = 0;
    std::cout << "[myList::clear] clear list, delete all elements" << std::endl;
    return *this;
}

myList::Node *myList::getNode(int index)
{
    Node *p = head;
    for (int i = 0; i < index; i++) {
        p = p->next;
    }
    return p;
}

myList &myList::show_list()
{
    Node *p = head->next;
    while (p != nullptr) {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
    return *this;
}