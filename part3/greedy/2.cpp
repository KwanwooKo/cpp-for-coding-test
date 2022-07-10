#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    vector<int> d;
    for (int i = 0; i < s.size(); i++) {
        d.push_back(s[i] - '0');
    }

    int ans = 0;
    for (int i = 0; i < d.size(); i++) {
        if (d[i] == 0 || d[i] == 1) {
            ans += d[i];
        }
        else if (ans == 0 || ans == 1) {
            ans += d[i];
        }
        else {
            ans *= d[i];
        }
    }
    cout << ans << endl;
    return 0;
}