#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int n;
char map[7][7];
vector<pair<int, int>> teacher;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
bool dfs() {
    for (pair<int, int> t : teacher) {
        int x = t.first;
        int y = t.second;
        int tmp_x = x;
        int tmp_y = y;
        for (int k = 0; k < 4; k++) {
            x = tmp_x;
            y = tmp_y;
            while (x >= 1 && y >= 1 && x <= n && y <= n) {
                if (map[x][y] == 'O') break;
                if (map[x][y] == 'S') return false;
                x += dx[k];
                y += dy[k];
            }
        }
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool ans = false;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'T') {
                teacher.push_back({i, j});
            }
        }
    }
    for (int x1 = 1; x1 <= n; x1++) {
        for (int y1 = 1; y1 <= n; y1++) {
            for (int x2 = 1; x2 <= n; x2++) {
                for (int y2 = 1; y2 <= n; y2++) {
                    if (x1 == x2 && y1 == y2) continue;
                    for (int x3 = 1; x3 <= n; x3++) {
                        for (int y3 = 1; y3 <= n; y3++) {
                            if (x1 == x3 && y1 == y3) continue;
                            if (x2 == x3 && y2 == y3) continue;
                            if (map[x1][y1] != 'X' || map[x2][y2] != 'X' || map[x3][y3] != 'X') continue;
                            map[x1][y1] = 'O';
                            map[x2][y2] = 'O';
                            map[x3][y3] = 'O';
                            bool flag = dfs();
                            if (flag) {
                                cout << "YES" << endl;
                                return 0;
                            }
                            map[x1][y1] = 'X';
                            map[x2][y2] = 'X';
                            map[x3][y3] = 'X';
                        }
                    }
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}