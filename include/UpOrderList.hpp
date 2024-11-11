#pragma once

#include "myList.hpp"

class UpOrderList : public myList {
public:
    /**
     * @brief 升序单链表添加元素
     *
     * @param data 元素值
     * @return UpOrderList& 自身引用
     */
    UpOrderList &add_element(int data);
    /**
     * @brief 升序单链表删除元素
     *
     * @param index 元素索引，从 1 开始
     * @return UpOrderList& 自身引用
     */
    UpOrderList &delete_element(int index);
};