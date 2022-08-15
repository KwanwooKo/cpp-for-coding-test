#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)10001
using namespace std;
typedef long long ll;
class DP_Part3_31 {
private:
    int n, m;
    int map[22][22];
    int memo[22][22];
    int ans;
public:
    DP_Part3_31() {
        cin >> n >> m;
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                map[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) {
                memo[i][j] = 0;
            }
        }
        memo[1][1] = map[1][1];
        memo[2][1] = map[2][1];
        memo[3][1] = map[3][1];
        ans = 0;
    }
    void solve() {
        // 모든 행에 대해서
        for (int j = 2; j <= m; j++) {
            // 열 확인 (2열 부터 확인)
            for (int i = 1; i <= n; i++) {
                memo[i][j] = max(memo[i + 1][j - 1] + map[i][j],
                                 max(memo[i][j - 1] + map[i][j],
                                     memo[i - 1][j - 1] + map[i][j]));
            }
        }
        print();
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cout << memo[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;
    }
    void print() {
        for (int i = 1; i <= n; i++) {
            ans = max(ans, memo[i][m]);
        }
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        DP_Part3_31 DP_Part3_31;
        DP_Part3_31.solve();
    }
    return 0;
}