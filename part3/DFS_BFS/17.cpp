#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
#define endl '\n'
using namespace std;
int map[201][201];
bool check[201][201];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, k, s, cx, cy;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> tmp_pq;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] != 0) {
                int virus = map[i][j];
                check[i][j] = true;
                pq.push({virus, i, j});
            }
        }
    }
    cin >> s >> cx >> cy;
    for (int i = 1; i <= s; i++) {
        while (!pq.empty()) {
            int virus = get<0>(pq.top());
            int x = get<1>(pq.top());
            int y = get<2>(pq.top());
            pq.pop();
            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                if (map[x][y] > map[nx][ny] && map[nx][ny] != 0) continue;
                if (check[nx][ny]) continue;
                map[nx][ny] = virus;
                tmp_pq.push({virus, nx, ny});
            }
        }
        while (!tmp_pq.empty()) {
            int virus = get<0>(tmp_pq.top());
            int x = get<1>(tmp_pq.top());
            int y = get<2>(tmp_pq.top());
            check[x][y] = true;
            tmp_pq.pop();
            pq.push({virus, x, y});
        }
    }
    cout << map[cx][cy] << endl;
    return 0;
}