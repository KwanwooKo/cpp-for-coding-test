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
using namespace std;
typedef long long ll;
class DP_Part2_3 {
private:
    int n;
    int memo[101][2];
public:
    DP_Part2_3() {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            memo[i][1] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> memo[i][0];
        }
    }
    void solve() {
        for (int i = 2; i <= n; i++) {
            memo[i][0] = memo[i - 1][1] + memo[i][0];
            memo[i][1] = memo[i - 1][0];
        }
        print();
    }
    void print() {
        cout << max(memo[n][0], memo[n][1]) << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    DP_Part2_3 DP_Part2_3;
    DP_Part2_3.solve();
    return 0;
}