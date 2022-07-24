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
            if (map[i][j] == 0) {
                stack<pair<int, int>> st;
                st.push(make_pair(i, j));
                while (!st.empty()) {
                    int x = st.top().first;
                    int y = st.top().second;
                    st.pop();
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
                        if (map[nx][ny] == 1) continue;
                        if (check[nx][ny]) continue;
                        check[nx][ny] = true;
                        st.push(make_pair(nx, ny));
                    }
                }
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}