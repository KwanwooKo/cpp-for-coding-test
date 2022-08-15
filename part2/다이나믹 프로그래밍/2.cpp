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
class DP_Part2_2 {
private:
    int n;
    int memo[30001];
public:
    DP_Part2_2() {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            memo[i] = INF;
        }
        memo[1] = 0;
        memo[2] = 1;
        memo[3] = 1;
        memo[4] = 2;
        memo[5] = 1;
    }
    void solve() {
        for (int i = 6; i <= n; i++) {
            if (i % 5 == 0) {
                memo[i] = min(memo[i], memo[i / 5] + 1);
            }
            if (i % 3 == 0) {
                memo[i] = min(memo[i], memo[i / 3] + 1);
            }
            if (i % 2 == 0) {
                memo[i] = min(memo[i], memo[i / 2] + 1);
            }
            memo[i] = min(memo[i], memo[i - 1] + 1);
        }   
        print();
    }
    void print() {
        cout << memo[n] << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    DP_Part2_2 DP_Part2_2;
    DP_Part2_2.solve();
    return 0;
}