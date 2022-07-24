#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;
int map[201][201];
int ans[201][201];
bool check[201][201];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1d", &map[i][j]);
        }
    }
    // bfs
    queue<pair<int, int>> q;
    q.push(make_pair(1, 1));
    check[1][1] = true;
    ans[1][1] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            if (check[nx][ny]) continue;
            if (map[nx][ny] == 0) continue;
            check[nx][ny] = true;
            ans[nx][ny] = ans[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    cout << ans[n][m] << endl;
    return 0;
}

// 5 6
// 101010
// 111111
// 000001
// 111111
// 111111