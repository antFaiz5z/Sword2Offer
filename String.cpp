//
// Created by faiz on 18-4-15.
//
#include "String.h"

#include <iostream>
#include <cstring>

void String::local_main_replace_space() {

    auto *string = new String();

    char *str = "hello warlal";
    string->replace_space(str, strlen(str));

    int length = 30;
    auto *str2 = (char *) (malloc(sizeof(char) * length));
    char tmp[] = "what the fuck";
    strcpy(str2, tmp);
    string->replace_space_standard(str2, 30);
}

void String::replace_space(char *str, int length) {

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

void String::replace_space_standard(char *str, int length) {

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

