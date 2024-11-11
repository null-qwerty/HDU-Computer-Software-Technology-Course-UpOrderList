#include "UpOrderList.hpp"

UpOrderList &UpOrderList::add_element(int data)
{
    // 维护链表升序
    Node *p = head->next;
    int index = 1;
    while (p != nullptr && p->data < data) {
        p = p->next;
        index++;
    }
    insert(index, data);
    return *this;
}

UpOrderList &UpOrderList::delete_element(int index)
{
    del(index);
    return *this;
}