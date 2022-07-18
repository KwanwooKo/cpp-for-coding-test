#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int solution(string s) {
    int answer = s.size();
    int count = 1;
    string cmp = "";
    string tmp = "";
    string ans = "";
    int str_Count = 1; // 반복되는 문자열의 횟수
    int index = 0;
    int i = 0;
    bool flag = false;
    while (1) {
        if (count == s.size()) {
            break;
        }
        if (index == s.size()) {
            if (str_Count != 1) {
                ans += to_string(str_Count);
            }
            ans += cmp;
            if (answer > ans.size()) {
                answer = ans.size();
            }
            cmp = "";
            tmp = "";
            ans = "";
            str_Count = 1;
            count++;
            index = 0;
            i = 0;
            continue;
        }
        index = i;
        if (!flag) {
            if (index + count <= s.size()) {
                for (i = index; i < index + count; i++) {
                    cmp += s[i];
                }
            }
            else {
                for (i = index; i < s.size(); i++) {
                    cmp += s[i];
                }
            }
            index = i;
        }
        if (i + count <= s.size()) {
            for (int j = i; j < i + count; j++) {
                tmp += s[j];
            }
        }
        else {
            for (int j = i; j < s.size(); j++) {
                tmp += s[j];
            }
        }
        if (cmp == tmp) {
            flag = true;
            str_Count++;
            tmp = "";
            i += count;
        }
        else {
            if (str_Count != 1) {
                ans += to_string(str_Count);
            }
            ans += cmp;
            flag = false;
            str_Count = 1;
            cmp = "";
            tmp = "";
        }
    }

    return answer;
}
int main(void) {
    string s;
    cin >> s;
    int ans = solution(s);
    cout << ans << endl;
    return 0;
}