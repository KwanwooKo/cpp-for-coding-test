#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#define endl '\n'
using namespace std;
int map[1001][1001];
bool check[1001][1001];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
void dfs(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (check[nx][ny]) continue;
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        check[nx][ny] = true;
        dfs(nx, ny);
    }
}
int main(void) {
    int ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf(" %1d", &map[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (check[i][j]) continue;
            dfs(i, j);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

// 4 5
// 00110
// 00011
// 11111
// 00000

//15 14
//00000111100000
//11111101111110
//11011101101110
//11011101100000
//11011111111111
//11011111111100
//11000000011111
//01111111111111
//00000000011111
//01111111111000
//00011111111000
//00000001111000
//11111111110011
//11100011111111
//11100011111111