//
// Created by Faiz on 2019/4/23 0023.
//

#ifndef JIANZHIOFFER_OTHERS_H
#define JIANZHIOFFER_OTHERS_H

#include <cstdint>
#include <climits>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

struct TimeSegment {
    uint64_t btime;
    uint64_t etime;

    TimeSegment() : btime(0), etime(0) {}

    TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_) {}
};

class Others {
public:

    //牛客
    //给出若干左闭右开（也许相反）区间，保留begin至end之间部分
    void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment);
    //将代码中注释部分删去，包括//与/**/，考虑转义符
    void removeAnnotation();
    //计算字符串中数字部分之和
    void string2digitalComputation();

    //bytedance
    void bytedance_one();//error 30%
    void bytedance_two();//error
    void bytedance_bt(vector<int> &score, vector<int> &divide, int n, int *max_score, int now_score, int direction,
                      int index);

    //牛客
    //'?'可为'A'或'B'，使丑陋数（叠词）最小
    void ugly();
    //0~n-1中选k个数之和为n的倍数1
    void combination();//error 10%
    void find(int &ret, int n, int k, int start, int now, int rest);
    //连续走n步（每次都可前进或后退），覆盖距离的期望
    void expectation();//error 50%,运行超时
    void insert(float &sum, float &count, int n, int now, int sum_now, int ma, int mi);

    //pdd
    //用数组B中尽量大的一个数替换数组A中的一个数使其严格递增
    void pdd_one();
    //判断各字符串是否可以头尾相接形成环（相接即字符相同）
    bool pdd_two();
    //bool search(vector<pair<char, char >> &v2, unordered_multimap<char, char> &s, int index);

    //网易互联网
    //大数求公约数
    void netease_one();
    //求给出数是否是已输入数字集的某个子集的或运算结果（1为添加数字，2为判断给出数）
    void netease_two();//error, 30%,内存超出限制
    //给出n个数，分别求当i等于1~n时所有长度为i的的连续子序列的最大值中的最小值
    void netease_three();//error, 60%,循环超时
    //给出优秀01序列S,判断01序列T是否优秀
    //（任意两优秀序列拼接而成的序列也为优秀序列，若某序列优秀则其翻转后再去除前导0的序列也优秀）
    //(例如： 1100 -> 110011)
    void netease_four();

    //网易雷火
    //判断每一步点击点中的窗口ID
    void leiho_one();//acc
    //bercon-locott??bst 查找
    void leiho_two();
    //输入包含中英文及符号表情的十六进制utf-8字符串，计算结尾坐标
    void leiho_three();//error, 0%
    void read(const unsigned char &chara, int &now_x, int &now_height);
    void addx(int &now_x, int &now_height, int wx);
    void addy(int &now_height);
    //一串数字序列，两人轮流采用最优策略拿取最左或最右元素，得分为每次取数与上次取数（第一次为0）之差绝对值之和，输出两人得分
    void leiho_four();//error, 8%
    //根据给出程序（输入x则输出相应y）,猜测f(x)
    void leiho_five();//error ,0%

    //网易互娱模拟
    //计税，四舍五入
    void intermo_one();//acc
    //字符串压缩，四个及以上字母为字典序连续压缩为‘头-尾’
    void intermo_two();//acc
    //由一个数的两种进制表示拼接而成的字符串求其十进制
    void intermo_three();//error，0%
    int calculate(char c);

    //DJI
    void dji_one();//error, 50%
    void dji_one_bt(vector<pair<int, int>> &mp, int &max_sum, int index, int now_sum, int rest_time);
    void dji_two();//acc
    void dji_three();//error, 0%
    void dji_three_bt1(vector<int> &price, vector<int> &like_price, int rest_v, int &ret);
    void dji_three_bt2(vector<int> &price, vector<int> &like_price, int index, int count, int rest_v, int &ret);

    //zoom
    void zoom_one();//acc

    //huawei
    void huawei_one();//acc
    void huawei_two();//acc
    void huawei_three();//error, 80%
    void huawei_three_find(string &name, unordered_map<string, int> &people_get, vector<unordered_set<string>> &groups);

    //didi
    void didi_one();//TLB, 9%
    void didi_two();//TLB, 0%

    //pdd2
    void pdd2_one();
    void pdd2_two();
    void pdd2_three();
    void pdd2_four();

    void gbits_one();//40%
    void gbits_two();//20%

private:
    //void leiho_three();
    int w, xe, ye, xc, yc, px, py, x, y;
    bool eng = false, chs = false, emo = false;
    vector<pair<int, int>> emoji;

};


#endif //JIANZHIOFFER_OTHERS_H
