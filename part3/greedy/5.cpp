#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int memo[11];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        memo[num]++;
        d.push_back(num);
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        n -= memo[i];
        ans += memo[i] * n;
    }
    cout << ans << endl;
    return 0;
}