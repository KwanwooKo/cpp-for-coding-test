#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)10001
using namespace std;
typedef long long ll;
class DP_Part3_34 {
private:
    int n, ans;
    int memo[2001];
    int d[2001];
public:
    DP_Part3_34() {
        cin >> n;
        ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> d[i];
            memo[i] = 1;
        }
    }
    void solve() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (d[i] < d[j]) {
                    memo[i] = max(memo[i], memo[j] + 1);
                }
            }
        }
        // display();
        print();
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            cout << memo[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        for (int i = 1; i <= n; i++) {
            ans = max(ans, memo[i]);
        }
        cout << n - ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    DP_Part3_34 DP_Part3_34;
    DP_Part3_34.solve();
    return 0;
}