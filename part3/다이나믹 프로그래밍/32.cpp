#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)10001
using namespace std;
typedef long long ll;
class DP_Part3_32 {
private:
    int n, ans;
    int d[502][502];
    int memo[502][502];
public:
    DP_Part3_32() {
        int count = 1;
        ans = 0;
        for (int i = 0; i <= 500; i++) {
            for (int j = 0; j <= 500; j++) {
                d[i][j] = 0;
                memo[i][j] = 0;
            }
        }
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= count; j++) {
                cin >> d[i][j];
                memo[i][j] = d[i][j];
            }
            count++;
        }
    }
    void solve() {
        int count = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= count; j++) {
                memo[i + 1][j] = max(memo[i + 1][j], memo[i][j] + d[i + 1][j]);
                memo[i + 1][j + 1] = max(memo[i + 1][j + 1], memo[i][j] + d[i + 1][j + 1]);
            }
            count++;
        }
        // display();
        print();
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << memo[i][j] << ' ';
            }
            cout << endl;
        }
    }
    void print() {
        for (int i = 1; i <= n; i++) {
            ans = max(ans, memo[n][i]);
        }
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    DP_Part3_32 DP_Part3_32;
    DP_Part3_32.solve();
    return 0;
}