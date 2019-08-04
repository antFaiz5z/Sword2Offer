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





