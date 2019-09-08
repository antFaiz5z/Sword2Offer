//
// Created by Faiz on 2019/4/23 0023.
//

#include "Others.h"


void Others::MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment) {

    for (auto it = lstTimeSegment.begin(); it != lstTimeSegment.end(); it++) {

        if (nBeginTime > it->etime) {
            continue;
        }
        if (nEndTime < it->btime) {
            lstTimeSegment.insert(it, TimeSegment(nBeginTime, nEndTime));
            return;
        }
        if (nBeginTime >= it->btime && nEndTime <= it->etime) {
            return;
        }
        if (nBeginTime < it->btime) {
            it->btime = nBeginTime;
            if (nEndTime >= it->btime && nEndTime <= it->etime) {
                return;
            }
        }

        auto it3 = it;
        auto it2 = ++it3;
        for (; it2 != lstTimeSegment.end();) {
            //show(lstTimeSegment);
            if (nEndTime >= it2->etime) {
                it->etime = nEndTime;
                it2 = lstTimeSegment.erase(it2);
            } else if (nEndTime >= it2->btime && nEndTime < it2->etime) {
                it->etime = it2->etime;
                lstTimeSegment.erase(it2);
                return;
            } else {
                it->etime = nEndTime;
                return;
            }
        }
    }
}

void Others::removeAnnotation() {//error

    char *s = (char *) malloc(50);
    bool multi = false;

    while (scanf("%s\n", s)) {
        string tmp = s;
        for (int i = 0; i < tmp.size(); ++i) {
            if (tmp[i] == '/' && tmp[i + 1] == '/') {
                if (i > 0 && tmp[i - 1] == '\\') {
                    continue;
                }
                break;
            }
            if (tmp[i] == '/' && tmp[i + 1] == '*') {
                if (i > 0 && tmp[i - 1] == '\\') {
                    continue;
                }
                multi = true;
            }
            if (multi) {
                if (tmp[i] == '*' && tmp[i + 1] == '/') {
                    multi = false;
                }
            } else {
                cout << tmp[i];
            }
        }
    }
}

void Others::string2digitalComputation() {

    string tmp;
    cin >> tmp;
    int ret = 0;
    int ch, now = 0;
    bool first = true;
    bool negative = false;

    for (char i : tmp) {

        if (i < '0' || i > '9') {
            if (i == '-' && first) {
                negative = true;
            }
            if (!first) {
                ret = negative ? ret - now : ret + now;
                now = 0;
                first = true;
                negative = i == '-';
            }
            continue;
        }
        ch = i - '0';
        if (ch == 0 && first) {
            continue;
        }
        now = now * 10 + ch;
        first = false;

    }
    ret = negative ? ret - now : ret + now;
    cout << ret;
}

void Others::bytedance_one() {


    vector<int> a{1, 2, 10}, b{1, 2, 3};
    int n = a.size();
    int x = 0;
    int y = 0;
    int greater = 0;
    int same = 0;

/*    cin >> n;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        a.push_back(j);
    }
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        b.push_back(j);
    }*/
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    while (x < n) {
        if (a[x] > b[y] || y >= n) {
            ++greater;
        } else if (a[x] == b[y]) {
            ++same;
        } else if (a[x] < b[y]) {
            ++x;
            continue;
        }
        ++x;
        ++y;

    }

    cout << greater * 2 + same - n << endl;
}

void Others::bytedance_two() {


    vector<int> score{2, 7, 9, 4, 3};
    int n = score.size();
    vector<int> divide;
    int *max_score = (int *) malloc(sizeof(int));
    //int *now_score = (int *)malloc(sizeof (int));
    //int *direction = (int *)malloc(sizeof (int));
    *max_score = 0;
    //*now_score = 0;
    //*direction = 1;

    /*cin >> n;
    for (int i = 0; i < n; ++i) {
        int j;
        cin >> j;
        score.push_back(j);
    }*/

    bytedance_bt(score, divide, n, max_score, 0, 1, 0);
    cout << *max_score << endl;

}

void Others::bytedance_bt(vector<int> &score, vector<int> &divide, int n, int *max_score, int now_score, int direction,
                          int index) {

    if (index >= n) {
        *max_score = max(*max_score, now_score);
        return;
    }
    int begin = 1, end;
    if (index == 0) {
        end = min(2, n);
    } else {
        end = min(divide[divide.size() - 1] * 2, n - index);
    }
    for (int i = begin; i <= end; ++i) {
        divide.push_back(i);
        //index += i;
        int sum = 0;
        if (direction) {
            for (int j = 0; j < i; ++j) {
                sum += score[index + j];
            }
            //*now_score += sum;
        }
        //direction = 1 - direction;
        bytedance_bt(score, divide, n, max_score, now_score + sum, 1 - direction, index + i);
        //*now_score -= sum;
        divide.pop_back();
    }
}

void Others::ugly() {

    string s;
    cin >> s;

    int now = 0, ret = 0;
    char before;
    while (s[now] == '?' && now < s.size() - 1) ++now;

    before = s[now];
    while (++now <= s.size() - 1) {
        if (s[now] == before) {
            ++ret;
        } else if (s[now] == '?') {
            before = before == 'A' ? 'B' : 'A';
        } else {
            before = s[now];
        }
    }
    cout << ret << endl;
}

void Others::combination() {

    int n, k;
    cin >> n >> k;

    int max = 0, ret = 0;
    for (int i = 0; i < k; ++i) {
        max += (n - i - 1);
    }
    int j = 1;
    while (j * n <= max) {
        cout << j * n << ":" << max << endl;
        find(ret, n, k, 0, 0, j * n);
        cout << j << ":" << ret << endl;
        ++j;
    }
    cout << ret << endl;
}

void Others::find(int &ret, int n, int k, int start, int now, int rest) {

    if (now == k) {
        if (rest == 0) {
            ++ret;
        }
        return;
    }
    for (int i = start; i < n - k + now; ++i) {
        if (i > rest) {
            return;
        } else {
            find(ret, n, k, start + 1, now + 1, rest - i);
        }
    }
}

void Others::expectation() {

    int n;
    cin >> n;

    float sum = 0;
    float count = 0;
    insert(sum, count, n, 0, 0, 0, 0);

    printf("%.1f", sum / count);
    //cout << sum / count << endl;
}

void Others::insert(float &sum, float &count, int n, int now, int sum_now, int ma, int mi) {

    if (now == n) {
        sum += (ma - mi + 1);
        ++count;
        return;
    }
    insert(sum, count, n, now + 1, sum_now + 1, max(ma, sum_now + 1), mi);
    insert(sum, count, n, now + 1, sum_now - 1, ma, min(sum_now - 1, mi));
}

void Others::pdd_one() {

    string line;
    getline(cin, line);
    stringstream ss1(line);
    vector<int> nums1;
    int x;
    while (ss1 >> x) nums1.push_back(x);
    getline(cin, line);
    stringstream ss2(line);
    vector<int> nums2;
    while (ss2 >> x) nums2.push_back(x);
    sort(nums2.begin(), nums2.end());

    for (auto &i : nums1) cout << i;
    cout << endl;
    for (auto &i : nums2) cout << i;
    cout << endl;

    bool find = false;
    for (int i = 1; i < nums1.size(); ++i) {
        if (nums1[i] <= nums1[i - 1]) {
            for (int j = nums2.size() - 1; j >= 0; --j) {
                if ((i == 1 || (nums2[j] > nums1[i - 2])) && nums2[j] < nums1[i]) {
                    nums1[i - 1] = nums2[j];
                    find = true;
                    break;
                }
                if ((i == nums1.size() - 1 || (nums2[j] < nums1[i + 1])) && nums2[j] > nums1[i - 1]) {
                    nums1[i] = nums2[j];
                    find = true;
                    break;
                }
            }
            if (find) {
                for (auto &i : nums1) cout << i;
                cout << endl;
            } else {
                cout << "NO" << endl;
            }
            break;
        }
    }
}

bool Others::pdd_two() {

/*    string tmp;
    vector<string> v;
    while (cin >> tmp) {
        v.push_back(tmp);
    }
    unordered_map<pair<char, char>, bool> map;
    for (auto &i: v) {
        map.insert(make_pair(i[0], i[i.size() - 1]), false);
    }
    map.begin()->second = true;
    return search(map, 1, map.begin()->first.first, map.begin()->first.second);*/
    return false;
}

void Others::netease_one() {}

void Others::netease_two() {

    int n, a, b;
    cin >> n;
    bool find = false;
    vector<int> nums;
    vector<vector<int>> res(n, vector<int>());

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &a, &b);
        if (a == 1) {
            nums.push_back(b);
            int count = nums.size();
            res[count - 1].push_back(b);
            for (int j = 0; j < count - 1; ++j) {
                for (auto &k : res[j]) {
                    res[count - 1].push_back(b | k);
                }
            }
        } else {
            for (int j = 0; j < nums.size(); ++j) {
                for (auto &k : res[j]) {
                    if (k == b) {
                        find = true;
                        break;
                    }
                }
                if (find) break;
            }
            if (find) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
            find = false;
        }
    }

}

void Others::netease_three() {

    int n, tmp, min_num = INT_MAX;
    cin >> n;

    vector<int> nums, ret;

    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        nums.push_back(tmp);
    }

    for (auto &i: nums) {
        min_num = min(min_num, i);
    }
    ret.push_back(min_num);
    for (int i = 1; i < n; ++i) {
        min_num = INT_MAX;
        for (int j = 0; j < n - i; ++j) {
            nums[j] = max(nums[j], nums[j + 1]);
            min_num = min(min_num, nums[j]);
        }
        ret.push_back(min_num);
    }

    for (auto &i: ret) {
        cout << i << " ";
    }
    cout << endl;

}

void Others::netease_four() {}

void Others::leiho_one() {

    int win_count, click_count;
    int x, y, w, h;
    cin >> win_count >> click_count;

    list<pair<int, vector<int>>> win;
    vector<pair<int, int>> click;
    for (int i = 0; i < win_count; ++i) {
        cin >> x >> y >> w >> h;
        win.emplace_front(make_pair(i + 1, vector<int>{x, y, w, h}));
    }
    for (int j = 0; j < click_count; ++j) {
        cin >> x >> y;
        click.emplace_back(make_pair(x, y));
    }

    for (int k = 0; k < click_count; ++k) {
        int cx = click[k].first;
        int cy = click[k].second;
        bool find = false;
        for (auto it = win.begin(); it != win.end(); ++it) {
            x = it->second[0];
            y = it->second[1];
            w = it->second[2];
            h = it->second[3];
            if (cx >= x && cx <= x + w && cy >= y && cy <= y + h) {
                find = true;
                cout << it->first << endl;
                pair<int, vector<int>> tmp(*it);
                win.erase(it);
                win.emplace_front(tmp);
                break;
            }
        }
        if (!find) cout << -1 << endl;
    }
}

void Others::leiho_two() {}

/*
void Others::leiho_three() {

    cin >> w >> xe >> ye >> xc >> yc >> px >> py;
    for (int i = 0; i < 20; ++i) {
        cin >> x >> y;
        emoji.emplace_back(make_pair(x, y));
    }
    x = 0;
    y = 0;
    int now_height = 0;
    unsigned char chara;

    while (scanf("%2X", &chara) != EOF) {
        read(chara, x, now_height);
    }
    cout << x << " " << y << endl;
}

void Others::read(const unsigned char &chara, int &now_x, int &now_height) {

    if (chara >= 0xE0) {
        addx(now_x, now_height, xc);
        chs = true;
        scanf("%4X", &chara);
    } else if (chara == '#') {
        eng = true;
        scanf("%2X", &chara);
        if (chara == '#') {
            addx(now_x, now_height, xe);
        } else if (chara == '0' || (chara >= '2' && chara <= '9')) {
            now_height = max(now_height, emoji[chara - '0'].second);
            addx(now_x, now_height, emoji[chara - '0'].first);
        } else if (chara == '1') {
            scanf("%2X", &chara);
            if (chara >= '0' && chara <= '9') {
                now_height = max(now_height, emoji[chara - '0' + 10].second);
                addx(now_x, now_height, emoji[chara - '0' + 10].first);
            } else {
                read(chara, now_x, now_height);
            }
        }
    } else {
        addx(now_x, now_height, xe);
        eng = true;
    }
}

void Others::addx(int &now_x, int &now_height, int wx) {
    if (now_x + px + wx > w) {
        addy(now_height);
        now_x = wx;
    } else {
        now_x += (px + wx);
    }
}

void Others::addy(int &now_height) {
    if (eng) now_height = max(now_height, ye);
    if (chs) now_height = max(now_height, yc);
    y += (now_height + py);
    eng = false;
    chs = false;
    now_height = 0;
}
*/


void Others::leiho_four() {

    int n, tmp;
    cin >> n;
    vector<int> nums;
    vector<int> ret(2, 0);
    vector<int> last(2, 0);
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        nums.push_back(tmp);
    }
    int x = 0, y = n - 1;

    while (x <= y) {
        if (abs(nums[x] - last[0]) >= abs(nums[y] - last[0])) {
            ret[0] += abs(nums[x] - last[0]);
            last[0] = nums[x++];
        } else {
            ret[0] += abs(nums[y] - last[0]);
            last[0] = nums[y--];
        }
        if (x <= y)
            if (abs(nums[x] - last[1]) >= abs(nums[y] - last[1])) {
                ret[1] += abs(nums[x] - last[1]);
                last[1] = nums[x++];
            } else {
                ret[1] += abs(nums[y] - last[1]);
                last[1] = nums[y--];
            }
    }
    cout << ret[0] << " " << ret[1];

}

void Others::leiho_five() {

    double x;
    cin >> x;
    if (x <= 0.66666667) {
        cout << -6.457329 * x * x - 1.6139155 * x + 3.0521;
    } else {
        cout << 0;
    }
}

void Others::intermo_one() {

    int n;
    double tmp;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        nums.push_back(tmp - 5000);
    }
    for (auto &i : nums) {

        if (i <= 0) {
            cout << 0 << endl;
        } else if (i <= 3000) {
            //printf("---%d\n", i * 0.03 + 0.5);
            cout << int(i * 0.03 + 0.5) << endl;
        } else if (i <= 12000) {
            //printf("---%d\n", 3000 * 0.03 + (i - 3000) * 0.1);
            cout << int(3000 * 0.03 + (i - 3000) * 0.1 + 0.5) << endl;
        } else if (i <= 25000) {
            cout << int(3000 * 0.03 + (12000 - 3000) * 0.1 + (i - 12000) * 0.2 + 0.5) << endl;
        } else if (i <= 35000) {
            cout << int(3000 * 0.03 + (12000 - 3000) * 0.1 + (25000 - 12000) * 0.2 + (i - 25000) * 0.25 + 0.5) << endl;
        } else if (i <= 55000) {
            cout << int(3000 * 0.03 + (12000 - 3000) * 0.1 + (25000 - 12000) * 0.2 + (35000 - 25000) * 0.25 +
                        (i - 35000) * 0.3 + 0.5) << endl;
        } else if (i <= 80000) {
            cout << int(3000 * 0.03 + (12000 - 3000) * 0.1 + (25000 - 12000) * 0.2 + (35000 - 25000) * 0.25 +
                        (55000 - 35000) * 0.3 + (i - 55000) * 0.35 + 0.5) << endl;
        } else {
            cout << int(3000 * 0.03 + (12000 - 3000) * 0.1 + (25000 - 12000) * 0.2 + (35000 - 25000) * 0.25 +
                        (55000 - 35000) * 0.3 + (80000 - 55000) * 0.35 + (i - 80000) * 0.45 + 0.5) << endl;
        }
    }

}

void Others::intermo_two() {


    int n;
    cin >> n;
    string tmp;
    vector<string> ss;
    vector<string> ret(n);
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ss.push_back(tmp);
    }

    for (int i = 0; i < n; ++i) {
        string t;
        int count = 1;
        ret[i].push_back(ss[i][0]);
        for (int j = 1; j < ss[i].size(); ++j) {
            t.push_back(ss[i][j]);
            if (ss[i][j] != ss[i][j - 1] + 1 || j == ss[i].size() - 1) {
                if (ss[i][j] == ss[i][j - 1] + 1) ++count;
                if (count >= 4) {
                    ret[i].push_back('-');
                    if (ss[i][j] != ss[i][j - 1] + 1)
                        ret[i].push_back(t[t.size() - 2]);
                    ret[i].push_back(t[t.size() - 1]);
                } else {
                    for (auto &c : t) {
                        ret[i].push_back(c);
                    }
                }
                count = 1;
                t.clear();
            } else {
                ++count;
            }
        }
    }
    for (auto &s: ret) {
        cout << s << endl;
    }


}

void Others::intermo_three() {


    int n, x, y;
    string tmp;
    vector<pair<pair<int, int>, string>> res;
    vector<int> ret;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> tmp;
        res.emplace_back(make_pair(make_pair(x, y), tmp));
    }
    for (int i = 0; i < n; ++i) {
        x = res[i].first.first;
        y = res[i].first.second;
        tmp = res[i].second;
        int m = 0, n = tmp.size() - 1;
        int right_i = 0;
        int left = 0, right = 0;
        while (m < n) {

            if (left <= right) {
                left = left * x + calculate(tmp[m++]);
                //cout << "left:" << left << endl;
            } else {
                int plus = 1;
                for (int j = 0; j < right_i; ++j) {
                    plus *= y;
                }
                right += (calculate(tmp[n--]) * plus);
                ++right_i;
                //cout << "right:" << right << endl;
            }
        }

        cout << max(left, right) << endl;
    }
}

int Others::calculate(char c) {
    if (c >= '0' && c < '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

void Others::dji_one_bt(vector<pair<int, int>> &mp, int &max_sum, int index, int now_sum, int rest_time) {

    for (int i = index; i < mp.size(); ++i) {
        if (rest_time >= mp[i].first) {
            max_sum = max(max_sum, now_sum + mp[i].second);
            dji_one_bt(mp, max_sum, index + 1, now_sum + mp[i].second, rest_time - mp[i].first);
        }
    }
}

void Others::dji_one() {

    int n, m, score, time, max_sum = 0;
    vector<pair<int, int>> mp;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> score >> time;
        mp.emplace_back(time, score);
    }
    dji_one_bt(mp, max_sum, 0, 0, m);
    cout << max_sum << endl;
}


void Others::dji_two() {

    int n, m;
    while (cin >> n >> m) {
        unordered_map<string, string> mp;
        string t1, t2;
        for (int i = 0; i < n; ++i) {
            cin >> t1 >> t2;
            mp.insert(make_pair(t1, t2));
        }
        for (int j = 0; j < m; ++j) {
            cin >> t1;
            cout << mp[t1] << endl;
        }
    }
}

void Others::dji_three_bt1(vector<int> &price, vector<int> &like_price, int rest_v, int &ret) {

    if (rest_v < 0) return;
    if (rest_v == 0) {
        ret = (ret + 1) % 10000007;
        return;
    }
    for (int i = 0; i < price.size(); ++i) {
        dji_three_bt1(price, like_price, rest_v - price[i], ret);
    }
}

void Others::dji_three_bt2(vector<int> &price, vector<int> &like_price, int index, int count, int rest_v, int &ret) {

    if (rest_v < 0) return;
    if (rest_v == 0) {
        ret = (ret + 1) % 10000007;
        return;
    }
    if (index == like_price.size()) {
        dji_three_bt1(price, like_price, rest_v, ret);
    }
    int i = 0;
    while (i <= count && (rest_v - like_price[index] * i) >= 0) {
        dji_three_bt2(price, like_price, index + 1, i, rest_v - like_price[index] * i, ret);
        ++i;
    }
}

void Others::dji_three() {

    int v, n, like_n, tmp;
    int ret = 0;
    vector<int> price;
    vector<int> like_price;

    cin >> v >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        price.push_back(tmp);
    }
    cin >> like_n;
    for (int j = 0; j < like_n; ++j) {
        cin >> tmp;
        like_price.push_back(price[tmp - 1]);
        price[tmp - 1] = 0;
    }
    for (int j = 0; j < like_n; ++j) {
        cout << "v:" << endl;
        v -= like_price[j] * (like_n - j - 1);
    }

    dji_three_bt2(price, like_price, 0, INT_MAX, v, ret);
    cout << ret << endl;
}

void Others::zoom_one() {

    int w, m, n;
    cin >> w >> m >> n;
    int x1, y1, x2, y2;

    y1 = (m - 1) / w;
    x1 = (y1 % 2 == 1) ? w - m % w : m % w - 1;
    y2 = (n - 1) / w;
    x2 = (y2 % 2 == 1) ? w - n % w : n % w - 1;
    cout << abs(x1 - x2) + abs(y1 - y2) << endl;
}

void Others::huawei_one() {

    string line, tmp;
    vector<string> ret;
    int count;
    getline(cin, line);
    stringstream ss(line);
    ss >> tmp;
    ret.emplace_back("");
    while (ss >> tmp) {
        if (tmp == "A") {
            ret.emplace_back("12");
            ret.emplace_back("34");

        } else if (tmp == "B") {
            ret.emplace_back("AB");
            ret.emplace_back("CD");
        } else {
            ret.push_back(tmp);
        }
    }
    count = ret.size();
    int m;
    while (count > 0) {
        m = count % 16;
        count /= 16;
        if (m >= 10) {
            ret[0].push_back(char('A' + m - 10));
        } else {
            ret[0].push_back(char('0' + m));
        }
    }
    reverse(ret[0].begin(), ret[0].end());
    cout << ret[0];
    for (int i = 1; i < ret.size(); ++i) {
        cout << " " << ret[i];
    }
    cout << endl;
}

void Others::huawei_two() {

    int m, n;
    int ten = 0, one = 0;
    cin >> m >> n;
    for (int i = m; i < n; ++i) {
        bool zhi = true;
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) {
                zhi = false;
                break;
            }
        }
        int tmp = i;
        if (zhi) {
            one += (tmp % 10);
            tmp /= 10;
            ten += (tmp % 10);
        }
    }
    cout << min(ten, one) << endl;
}

void Others::huawei_three() {

    string first, tmp;
    int group_count;
    int ret = 0;
    cin >> first >> group_count;
    unordered_map<string, int> people_get;
    vector<unordered_set<string>> groups(group_count);
    for (int i = 0; i < group_count; ++i) {
        cin >> tmp;
        string name;
        for (char j : tmp) {
            if (j != ',') {
                name += j;
            } else {
                groups[i].insert(name);
                people_get[name] = 0;
                name.clear();
            }
        }
        if (!name.empty()) {
            groups[i].insert(name);
            people_get[name] = 0;
        }
    }
    people_get[first] = 1;
    huawei_three_find(first, people_get, groups);

    for (auto &i : people_get) {
        if (i.second != 0) ++ret;
    }
    cout << ret << endl;

}

void
Others::huawei_three_find(string &name, unordered_map<string, int> &people_get, vector<unordered_set<string>> &groups) {

    for (auto &g : groups) {
        if (g.find(name) != g.end()) {
            for (auto n : g) {
                if (people_get.find(n) != people_get.end() && people_get[n] == 0) {
                    ++people_get[n];
                    huawei_three_find(n, people_get, groups);
                }
            }
        }
    }
}

void didi_one_bfs(vector<string> &nums, vector<char> &chas, int index) {

    if (index == nums.size() - 1) {
        return;
    }
    if (stoi(nums[index + 1]) < stoi(nums[index]))
        if (chas[index] == '+' || chas[index] == '-') {
            if (((index == 0) || (chas[index - 1] == '+' || chas[index - 1] == '-')) &&
                ((index == nums.size() - 1) || (chas[index + 1] == '+' || chas[index + 1] == '-'))) {
                string tmp = nums[index];
                nums[index] = nums[index + 1];
                nums[index + 1] = tmp;
            }
        } else if (chas[index] == '*' || chas[index] == '/') {
            string tmp = nums[index];
            nums[index] = nums[index + 1];
            nums[index + 1] = tmp;
        }
    for (int i = index + 1; i < nums.size(); ++i) {
        didi_one_bfs(nums, chas, i);
    }
}

void Others::didi_one() {

    int n;
    cin >> n;
    vector<string> nums(n);
    vector<char> chas(n - 1);
    cin >> nums[0];
    for (int i = 0; i < n - 1; ++i) {
        cin >> chas[i];
        cin >> nums[i + 1];
    }

    for (auto &i : nums) {
        cout << i << " ";
    }
    for (auto &i : chas) {
        cout << i << " ";
    }
    cout << endl;
    didi_one_bfs(nums, chas, 0);

    cout << nums[0] << ' ';
    for (int i = 0; i < n - 1; ++i) {
        cout << chas[i] << ' ';
        cout << nums[i + 1] << ' ';
    }
    cout << endl;
}

void
didi_two_dfs(vector<int> &a, vector<int> &b, int indexa, int indexb, int &ret, int now, int n, int rest, int cost) {

    if (rest < 0 || indexa >= n || indexb >= n) {
        return;
    }
    if ((2 * n - indexa - indexb) <= rest) {
        ret = max(ret, now);
    }
    for (int i = indexa; i < n; ++i) {
        for (int j = indexb; j < n; ++j) {
            if (a[i] == b[j]) {
                didi_two_dfs(a, b, i + i, j + 1, ret, now + 1, n, rest - cost, cost);
            }
        }
    }
    for (int i = indexb; i < n; ++i) {
        for (int j = indexa; j < n; ++j) {
            if (a[j] == b[i]) {
                didi_two_dfs(a, b, i + i, j + 1, ret, now + 1, n, rest - cost, cost);
            }
        }
    }

}

void Others::didi_two() {

    int n, total, cost;
    cin >> n >> total >> cost;
    int x, ret = 0;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        cin >> x;
        b.push_back(x);
    }
    didi_two_dfs(a, b, 0, 0, ret, 0, n, total, cost);
    cout << ret << endl;
}

void pdd2_one_dfs(vector<int> &nums, int n, vector<int> &ret, int index) {

    if (ret.size() == n) {
        cout << ret[0];
        for (int i = 1; i < n; ++i) {
            cout << "," << ret[i];
        }
        cout << endl;
        exit(0);
    }
    for (int i = index; i <= nums.size() - n + ret.size(); ++i) {
        bool ok = false;
        cout << nums[i] << endl;
        if (ret.empty()) {
            ok = true;
        } else if (ret.back() % 2 == 0) {
            if ((nums[i] % 2 == 0 && nums[i] < ret.back()) || nums[i] % 2 == 1) {
                ok = true;
            }
        } else {
            if (nums[i] % 2 == 1 && nums[i] < ret.back()) {
                ok = true;
            }
        }
        if (ok) {
            ret.push_back(nums[i]);
            pdd2_one_dfs(nums, n, ret, i + 1);
            ret.pop_back();
        }
    }
}

void Others::pdd2_one() {

    int n, tmp = 0;
    vector<int> nums, ret;
    string line;
    getline(cin, line);

    for (char i : line) {
        if (i == ',' || i == ';') {
            nums.push_back(tmp);
            tmp = 0;
        } else {
            tmp = tmp * 10 + i - '0';
        }
    }
    n = tmp;

    pdd2_one_dfs(nums, n, ret, 0);

}

void Others::pdd2_two() {

}

void Others::pdd2_three() {

    int n, tmp, ma = 0;
    float zo = 1;
    cin >> n;
    vector<int> all;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        ma = max(ma, tmp);
        zo *= (float) tmp;
        all.push_back(tmp);
    }
    //cout << "zo:" << zo << endl;
    float ret = 0;
    for (int j = 1; j <= ma; ++j) {
        float chan = 0, tmp1 = 1, tmp2 = 1;
        for (int k = 0; k < n; ++k) {
            tmp1 *= min(all[k], j);
            tmp2 *= min(all[k], j - 1);
        }
        //cout << "1:" << tmp1 << ", 2:" << tmp2 << endl;
        chan = (tmp1 - tmp2) / zo;
        //cout << chan << endl;
        ret += ((float) j * chan);
    }
    printf("%.2f\n", ret);
    //cout << ret << endl;
}

void Others::pdd2_four() {

    int m, n, k;
    cin >> m >> n >> k;

    vector<int> nums;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            nums.push_back(i * j);
        }
    }
    sort(nums.begin(), nums.end());
    for (auto &i : nums) {
        cout << i << endl;
    }
    cout << nums[nums.size() - k] << endl;

}

void Others::gbits_one() {

    string a, b;
    cin >> a >> b;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 && j >= 0) {

        if (a[i] == b[j]) {
            if (j-- == 0) {
                cout << i + 1 << endl;
                return;
            }
        }
        i--;
    }
    cout << "0" << endl;

}

void Others::gbits_two() {

    multimap<int, vector<int>> cost;
    set<int> points;
    int ret = 0;
    int n, m, a, b, c;
    cin >> n >> m;
    int *count = new int[n + 1]();

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        cost.insert(make_pair(c, vector<int>{a, b}));
    }
    for (auto &it : cost) {
        if ((points.find(it.second[0]) != points.end() && points.find(it.second[1]) != points.end())
            || count[it.second[0]] >= 3 || count[it.second[1]] >= 3) {
            continue;
        }
        ++count[it.second[0]];
        ++count[it.second[1]];
        if (points.find(it.second[0]) == points.end())
            points.insert(it.second[0]);
        if (points.find(it.second[1]) == points.end())
            points.insert(it.second[1]);
        ret += it.first;
    }
    for (int i = 1; i <= n; ++i) {
        if (points.find(i) == points.end()) {
            cout << -1 << endl;
            return;
        }
    }
    cout << ret << endl;
}

void iqiyi_one_dfs(vector<int> &than, vector<int> &nums, vector<bool> &used, int n, int index, int &ret) {

    if (nums.size() == n) {
        ++ret;
        return;
    }
    if (index == 0) {
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i);
            used[i] = true;
            iqiyi_one_dfs(than, nums, used, n, index + 1, ret);
            used[i] = false;
            nums.pop_back();
        }
    } else if (than[index - 1] == 0 && nums.back() < n) {
        for (int i = nums.back() + 1; i <= n; ++i) {
            if (used[i] == false) {
                nums.push_back(i);
                used[i] = true;
                iqiyi_one_dfs(than, nums, used, n, index + 1, ret);
                used[i] = false;
                nums.pop_back();
            }
        }
    } else if (than[index - 1] == 1 && nums.back() > 1) {
        for (int i = 1; i < nums.back(); ++i) {
            if (used[i] == false) {
                nums.push_back(i);
                used[i] = true;
                iqiyi_one_dfs(than, nums, used, n, index + 1, ret);
                used[i] = false;
                nums.pop_back();
            }
        }
    }
}

void Others::iqiyi_one() {

    vector<int> than;
    int n, tmp, ret = 0;
    cin >> n;
    vector<int> nums;
    vector<bool> used(n, false);
    for (int i = 1; i <= n - 1; ++i) {
        cin >> tmp;
        than.push_back(tmp);
    }
    iqiyi_one_dfs(than, nums, used, n, 0, ret);
    cout << ret << endl;
}

void Others::iqiyi_two() {}




