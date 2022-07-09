#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int map[101][101];
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> list;
    for (int i = 1; i <= n; i++) {
        int cmp = 10001;
        for (int j = 1; j <= m; j++) {
            cin >> map[i][j];
            cmp = min(cmp, map[i][j]);
        }
        list.push_back(cmp);
    }
    int ans = 0;
    for (int i = 0; i < list.size(); i++) {
        ans = max(ans, list[i]);
    }
    cout << ans << endl;
    return 0;
}