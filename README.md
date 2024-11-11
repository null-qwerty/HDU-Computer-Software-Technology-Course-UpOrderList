# 升序单链表

> 本仓库代码为计算机软件技术课程设计的代码，不保证为最优设计方案。

## 数据结构设计

使用单链表存储数据，链表节点定义如下：

```cpp
struct Node {
    int data;
    Node *next;
};
```

## 算法设计

### 设计思路及实现

对于任意数据结构，基本的操作有**增删改查**四种，而对于升序单链表而言，由于需要满足升序的特性，一般不会涉及到修改操作，因此只需要实现**增删查**三种操作。而修改操作可以通过删除和插入操作来实现。

在本仓库中，实现了以下内容：

- 基础的单链表类 `myList`，包含增删改查四种操作
- 升序单链表类 `UpOrderList`，继承自 `myList`，包含升序插入元素和删除元素的操作

对应类的定义如下：

```cpp
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
```

```cpp
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
```

### 重点代码解析

升序单链表的重点就是其特性，即如何维护链表的升序性。注意到，对于一个升序数列而言，删去任意一个元素后，剩下的数列仍然是升序的，因此，我们**仅仅需要在插入元素时维护链表的升序性**即可。

在 `UpOrderList` 类中，实现了 `add_element` 和 `delete_element` 两个方法，其中 `add_element` 方法的实现如下：

```cpp
UpOrderList &UpOrderList::add_element(int data)
{
    // 维护链表升序
    Node *p = head->next;   // 指向第一个元素
    int index = 1;
    while (p != nullptr && p->data < data) {    // 找到第一个大于 data 的元素
        p = p->next;
        index++;
    }
    insert(index, data);    // 在 index 处插入 data
    return *this;
}
```

当 `data` 大于链表中的所有元素时，`p` 指向 `nullptr`，此时 `index` 的值为链表长度加一，即在链表尾部插入元素。

## 测试

测试代码如下：

```cpp
#include <iostream>
#include <sstream>
#include <string>

#include "UpOrderList.hpp"

void generate_cmd(std::string cmd, UpOrderList &list)
{
    std::string cmd_name;
    std::stringstream ss(cmd);
    ss >> cmd_name;
    if (cmd_name == "add") {
        int data;
        ss >> data;
        list.add_element(data);
    } else if (cmd_name == "del") {
        int data;
        ss >> data;
        list.delete_element(data);
    } else if (cmd_name == "show") {
        list.show_list();
    } else {
        std::cout << "unknown command" << std::endl;
    }
}

int main()
{
    UpOrderList list;
    std::string cmd;

    std::cout << "commands: add <data>, del <index>, show" << std::endl;

    while (true) {
        std::getline(std::cin, cmd);
        if (cmd == "exit") {
            break;
        }
        generate_cmd(cmd, list);
    }
    return 0;
}
```

通过输入 `add` 命令添加元素，`del` 命令删除元素，`show` 命令显示链表内容，`exit` 命令退出程序：

```bash
./main
commands: add <data>, del <index>, show
add 4
add 3
add 1
add 2
show
1 2 3 4
del 2
show
1 3 4
exit
[myList::clear] clear list, delete all elements
[myList::~myList] delete list
```