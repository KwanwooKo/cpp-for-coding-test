#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;
int map[201][201];
bool check[201][201];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
int ans = 1;
void dfs(int x, int y, int count) {
    if (x == n && y == m) {
        ans = count;
        return;
    }
    check[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        if (check[nx][ny]) continue;
        if (map[nx][ny] == 0) continue;
        check[nx][ny] = true;
        dfs(nx, ny, count + 1);

    }
}
int main(void) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1d", &map[i][j]);
        }
    }
    check[1][1] = true;
    dfs(1, 1, 1);
    cout << ans << endl;
    return 0;
}

//5 6
//101010
//111111
//000001
//111111
//111111