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
int dx[] = {1, -1, 0, 0}; 
int dy[] = {0, 0, 1, -1};
int n, l, r;
int ans;
bool bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    int sum = map[x][y];
    vector<pair<int, int>> sum_list;
    check[x][y] = true;
    sum_list.push_back({x, y});
    while (!q.empty()) {
        int bx = q.front().first;
        int by = q.front().second;
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = bx + dx[k];
            int ny = by + dy[k];
            if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if (check[nx][ny]) continue;
            if (abs(map[nx][ny] - map[bx][by]) < l || abs(map[nx][ny] - map[bx][by]) > r) continue;
            check[nx][ny] = true;
            sum += map[nx][ny];
            sum_list.push_back({nx, ny});
            q.push({nx, ny});
        }
    }
    int count = sum_list.size();
    if (count == 1) {
        return false;
    }
    sum /= count;
    for (pair<int, int> coord : sum_list) {
        int nx = coord.first;
        int ny = coord.second;
        map[nx][ny] = sum;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }
    for (int k = 1; k <= 2000; k++) {
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (check[i][j]) continue;
                if (!flag) {
                    flag = bfs(i, j);
                }
                else {
                    bfs(i, j);
                }
            }
        }
//         출력
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                cout << map[i][j] << ' ';
//            }
//            cout << endl;
//        }
//        cout << endl;
//
        if (!flag) {
            if (k == 1) {
                ans = 0;
            }
            break;
        }
        else {
            ans++;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                check[i][j] = false;
            }
        }
    }

    cout << ans << endl;
    return 0;
}