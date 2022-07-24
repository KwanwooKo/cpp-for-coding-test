#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define MAX 1000000000
using namespace std;
typedef long long ll;
int n;
int oper_num[5];
vector<char> oper;
vector<char> print;
bool check[11];     // 연산자 사용 여부 확인
int ans_min = MAX, ans_max = -MAX;
vector<int> d;
void dfs(int count, int dest_count) {
    if (count == dest_count) {
        int sum = d[0];
        for (int i = 0; i < print.size(); i++) {
            if (print[i] == '+') {
                sum += d[i + 1];
            }
            if (print[i] == '-') {
                sum -= d[i + 1];
            }
            if (print[i] == '*') {
                sum *= d[i + 1];
            }
            if (print[i] == '/') {
                sum /= d[i + 1];
            }
        }
        if (ans_min > sum) {
            ans_min = sum;
        }
        if (ans_max < sum) {
            ans_max = sum;
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (check[i]) continue;
        check[i] = true;
        print.push_back(oper[i]);
        dfs(count + 1, dest_count);
        print.pop_back();
        check[i] = false;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        d.push_back(num);
    }
    for (int i = 1; i <= 4; i++) {
        cin >> oper_num[i];
        if (i == 1) {
            for (int j = 0; j < oper_num[i]; j++) {
                oper.push_back('+');
            }
        }
        if (i == 2) {
            for (int j = 0; j < oper_num[i]; j++) {
                oper.push_back('-');
            }
        }
        if (i == 3) {
            for (int j = 0; j < oper_num[i]; j++) {
                oper.push_back('*');
            }
        }
        if (i == 4) {
            for (int j = 0; j < oper_num[i]; j++) {
                oper.push_back('/');
            }
        }
    }
    dfs(0, oper.size());
    cout << ans_max << endl;
    cout << ans_min << endl;
    return 0;
}