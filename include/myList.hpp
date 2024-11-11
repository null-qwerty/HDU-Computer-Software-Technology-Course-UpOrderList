#pragma once

class myList {
public:
    struct Node {
        int data;
        Node *next;
    };

    myList();
    ~myList();

    myList &show_list();
    /**
     * @brief 获取链表长度
     *
     * @return int 链表长度
     */
    int lenth();
    /**
     * @brief 获取链表中的元素
     *
     * @param index 元素下标
     * @return int
     */
    int get(int index);
    /**
     * @brief 清空链表
     *
     */
    myList &clear();
    /**
     * @brief 获取链表中的节点
     *
     * @param index 节点下标
     * @return Node* 节点指针
     */
    Node *getNode(int index);
    /**
     * @brief 在链表尾部添加元素
     *
     * @param data 添加的元素
     */
    myList &addend(int data);
    /**
     * @brief 删除一个元素
     *
     * @param index 删除元素的下标
     */
    myList &del(int index);
    /**
     * @brief 插入一个元素
     *
     * @param index 插入元素的下标
     * @param data 插入的元素
     */
    myList &insert(int index, int data);
    /**
     * @brief 更改一个元素
     *
     * @param index 更改元素的下标
     * @param data 更改的元素
     */
    myList &replace(int index, int data);

protected:
    Node *head;
    int length;
};