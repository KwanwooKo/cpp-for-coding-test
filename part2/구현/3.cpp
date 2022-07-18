#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int map[51][51];
bool check[51][51];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, 1, -1, 0};
int main(void) {
    int n, m;
    cin >> n >> m;
    int x, y, dir;
    cin >> x >> y >> dir;
    x++;
    y++;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= m; j++) {
            cin >> map[i][j];
        }
    }
    int ans = 0;
    int count = 0;
    while (1) {
        // 일단 왼쪽 부터 확인
        // 왼쪽 방향에 가보지 않은 칸이 없으면 왼쪽으로 회전만
        // 왼쪽 방향에 가보지 않은 칸이 있으면 왼쪽으로 1칸 이동
        count++;
        if (dir == 0) dir = 2;
        else if (dir == 1) dir = 0;
        else if (dir == 2) dir = 3;
        else if (dir == 3) dir = 1;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (count == 4) {
            int tmp = dir;
            count = 0;
            if (dir == 0) dir = 3;
            else if (dir == 1) dir = 2;
            else if (dir == 2) dir = 1;
            else if (dir == 3) dir = 0;
            x = x + dx[dir];
            y = y + dy[dir];
            dir = tmp;
            if (map[x][y] == 1) {
                break;
            }
        }
        if (check[nx][ny] || map[nx][ny] == 1) continue;
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

        check[nx][ny] = true;
        x = nx;
        y = ny;
        ans++;
        count = 0;
    }
    cout << ans << endl;
    return 0;
}