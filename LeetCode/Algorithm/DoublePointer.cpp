//
// Created by Faiz on 2019/1/9 0009.
//

#include "DoublePointer.h"

#include <cmath>

vector<int> DoublePointer::twoSum(vector<int> &numbers, int target) {

    int i = 0, j = static_cast<int>(numbers.size() - 1);
    while (numbers[i] + numbers[j] != target){
        while (numbers[i] + numbers[j] > target){
            --j;
        }
        while (numbers[i] + numbers[j] < target){
            ++i;
        }
    }
    return vector<int>({i +1, j +1});
}

bool DoublePointer::judgeSquareSum(int c) {
    int i = 0, j = (int)sqrt(c);
    while (i <= j){
        int s = i *i + j *j;
        if (s > c ){
            --j;
        }else if (s < c){
            ++i;
        }else{
            return true;
        }
    }
    return false;
}

string DoublePointer::findLongestWord(string s, vector<string>& d) {

    string ret;
    unsigned long n = s.size();

    for (const auto &ms : d){
        unsigned long m = ms.size();
        unsigned long i = 0, j = 0;
        while (j < n){
            if (ms.at(i) == s.at(j)){
                ++i;
            }
            ++j;
            if (i == m){
                if (m > ret.size() || (m == ret.size() && ms > ret)){
                    ret = ms;
                }
                break;
            }
        }
    }
    return ret;
}

bool DoublePointer::isPalindrome(string s) {

    int i = 0, j = s.size() -1;
    while (i < j){

        while (i < j && !isalnum(s[i])) ++i;
        while (i < j && !isalnum(s[j])) --j;
        if (tolower(s[i++]) != tolower(s[j--])) return false;
    }
    return true;
}

vector<vector<string>> DoublePointer::partition(string s) {

    vector<vector<string>> ret;
    vector<string> sub;
    bt(s, ret, sub, 0);
    return ret;

}

void DoublePointer::bt(string &s, vector<vector<string>> &ret, vector<string> &sub, int index){

    if (index == s.size()){
        ret.push_back(sub);
        return;
    }
    for (int i = index; i < s.size(); ++i){

        string tmp = s.substr(index, i -index +1);
        if (isPalindrome(tmp)){
            sub.push_back(tmp);
            bt(s, ret, sub, i +1);
            sub.pop_back();
        }
    }
}

