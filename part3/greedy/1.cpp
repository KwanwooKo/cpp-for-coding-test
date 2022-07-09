#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
bool check[100001];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    int ans = 0;
    for (int i = 0; i < d.size(); i++) {
        if (check[i]) {
            continue;
        }
        int cmp = d[i];
        bool flag = false;
        for (int j = i; j < i + cmp; j++) {
            if (j > n) {
                flag = true;
                break;
            }
            if (cmp < d[j]) {
                flag = true;
                break;
            }
            check[j] = true;
        }
        if (!flag) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}