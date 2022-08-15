#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define endl '\n'
#define INF (int)1e9
#define MOD 796796
using namespace std;
typedef long long ll;
class DP_Part2_4 {
private:
    int memo[1001][3];
    int n;
    int ans;
public:
    DP_Part2_4() {
        cin >> n;
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j < 3; j++) {
                memo[i][j] = 0;
            }
        }
        memo[1][0] = 1;
        memo[2][0] = 1;
        memo[2][1] = 1;
        memo[2][2] = 1;
        ans = 0;
    }
    void solve() {
        for (int i = 3; i <= n; i++) {
            memo[i][0] = memo[i - 1][0] % MOD + memo[i - 1][1] % MOD + memo[i - 1][2] % MOD;
            memo[i][1] = memo[i - 2][0] % MOD + memo[i - 2][1] % MOD + memo[i - 2][2] % MOD;
            memo[i][2] = memo[i - 2][0] % MOD + memo[i - 2][1] % MOD + memo[i - 2][2] % MOD;
        }
        print();
        // display();
    }
    void display() {
        for (int i = 0; i <= n; i++) {
            int print = 0;
            for (int j = 0; j < 3; j++) {
                print += memo[i][j];
            }
            cout << print << ' ';
        }
        cout << endl;
    }
    void print() {
        for (int i = 0; i < 3; i++) {
            ans = ans % MOD + memo[n][i] % MOD;
            ans %= MOD;
        }
        cout << ans % MOD << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    DP_Part2_4 DP_Part2_4;
    DP_Part2_4.solve();
    return 0;
}