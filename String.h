//
// Created by faiz on 18-4-15.
//

#ifndef JIANZHIOFFER_STRING_H
#define JIANZHIOFFER_STRING_H


class String {

public:

    /*
     * 时间限制：1秒 空间限制：32768K 热度指数：565840
     * 本题知识点： 字符串
     * 请实现一个函数，将一个字符串中的空格替换成“%20”。
     * 例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
     */
    void replace_space(char *str, int length);

    void replace_space_standard(char *str, int length);

    static void local_main_replace_space();
};


#endif //JIANZHIOFFER_STRING_H
