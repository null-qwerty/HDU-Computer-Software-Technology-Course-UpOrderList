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
    } else if (cmd_name == "exit") {
        exit(0);
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