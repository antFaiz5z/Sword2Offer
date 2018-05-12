//
// Created by faiz on 18-4-25.
//
#include "Data_Structure.h"

#include <iostream>
#include <cstring>
#include <malloc.h>

void Data_Structure::local_main_replace_space() {

    auto *string = new Data_Structure();

    auto *str = const_cast<char *>("hello warlal");
    string->replace_space(str, static_cast<int>(strlen(str)));

    int length = 30;
    auto *str2 = (char *) (malloc(sizeof(char) * length));
    char tmp[] = "what the fuck";
    strcpy(str2, tmp);
    string->replace_space_standard(str2, 30);
}

void Data_Structure::replace_space(char *str, int length) {

    auto *tmp = new char[length * 3];
    int now = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            tmp[now++] = '%';
            tmp[now++] = '2';
            tmp[now++] = '0';
        } else {
            tmp[now++] = str[i];
        }
    }
    tmp[now] = '\n';
    str = tmp;
    std::cout << str << std::endl;
}

void Data_Structure::replace_space_standard(char *str, int length) {

    if (str == nullptr || length < 0) {
        return;
    }

    int i = 0;
    int old_length = 0;
    int space_count = 0;

    while (str[i] != '\0') {
        if (str[i] == ' ') {
            space_count++;
        }
        old_length++;
        i++;
    }

    int new_length = old_length + space_count * 2;
    if (new_length > length) {
        return;
    }

    int p_old_length = old_length;
    int p_new_length = new_length;

    while (p_old_length >= 0 && p_new_length > p_old_length) {

        if (str[p_old_length] == ' ') {
            str[p_new_length--] = '0';
            str[p_new_length--] = '2';
            str[p_new_length--] = '%';
        } else {
            str[p_new_length--] = str[p_old_length];
        }
        p_old_length--;
    }
    std::cout << str << std::endl;
}

void Data_Structure::local_main() {

    auto *array = new Data_Structure();
    vector<vector<int>> a = array->get_array(10, 10);

    double start = Utility::get_time();
    array->find_mine(15, a);
    array->find_mine(20, a);
    array->find_mine(-1, a);
    double end = Utility::get_time();
    Utility::print_during(start, end);

    start = Utility::get_time();
    array->find_standard(15, a);
    array->find_standard(20, a);
    array->find_standard(-1, a);
    end = Utility::get_time();
    Utility::print_during(start, end);
}


vector<vector<int>> Data_Structure::get_array(int m, int n) {
    vector<vector<int>> tmp;
    vector<int> tmp2;
    for (int l = 0; l < n; ++l) {
        tmp2.push_back(0);
    }
    for (int j = 0; j < m; ++j) {
        //tmp2.reserve(n);
        for (int i = 0; i < n; ++i) {
            tmp2[i] = i + j;
        }
        tmp.push_back(tmp2);
    }
    return tmp;
}

bool Data_Structure::find_mine(int target, vector<vector<int> > array) {
    for (int i = 0; i < array.size(); i++) {
        if (target >= array[i].front() && target <= array[i].back()) {
            for (int j = 0; j < array[i].size(); j++) {
                if (target == array[i][j]) {
                    cout << i << "," << j << endl;
                    return true;
                }
            }
        }
        if (target > array[i].back()) {
            continue;
        }
        if (target < array[i].front()) {
            cout << "not found." << endl;
            return false;
        }
    }
    cout << "not found." << endl;
    return false;
}

bool Data_Structure::find_standard(int target, vector<vector<int> > array) {

    unsigned long rows = array.size();
    unsigned long cols = array[0].size();

    auto i = static_cast<int>(rows - 1);
    int j = 0;
    while (0 <= i && j < cols) {
        if (target == array[i][j]) {
            cout << i << "," << j << endl;
            return true;
        } else if (target > array[i][j]) {
            j++;
        } else {
            i--;
        }
    }
    cout << "not found." << endl;
    return false;
}

void Data_Structure::local_main_printListFromTailToHead() {

    auto *head = new ListNode(-1);
    auto tmp = head;
    for (int i = 0; i < 10; ++i) {
        auto *node = new ListNode(i);
        head->next = node;
        head = head->next;
    }
    head = tmp;
    while (tmp) {
        std::cout << tmp->val << ", ";
        tmp = tmp->next;
    }
    std::cout << std::endl;

    auto *list = new Data_Structure();
    std::vector<int> ret = list->printListFromTailToHead(head);
    std::vector<int>::iterator it;
    for (it = ret.begin(); it != ret.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

std::vector<int> Data_Structure::printListFromTailToHead(ListNode *head) {

    std::vector<int> ret;
    while (head) {
        ret.insert(ret.begin(), head->val);
        head = head->next;
    }
    return ret;
}

void Data_Structure::push(int node) {
    s1.push(node);
}

int Data_Structure::pop() {
    int tmp;
    if (s2.empty()) {
        while (!s1.empty()) {
            tmp = s1.top();
            s2.push(tmp);
            s1.pop();
        }
    }
    tmp = s2.top();
    s2.pop();
    return tmp;
}

void Data_Structure::local_main_2stacks_1queue() {

    auto *main = new Data_Structure();
    main->push(10);
    main->push(9);
    std::cout << main->pop() << std::endl;
    main->push(8);
    std::cout << main->pop() << std::endl;

}