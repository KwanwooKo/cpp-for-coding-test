#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)10001
using namespace std;
typedef long long ll;
class DP_Part3_33 {
private:
    int n, ans;
    int memo[21];
    int price[21];
    int day[21];
public:
    DP_Part3_33() {
        ans = 0;
        cin >> n;
        for (int i = 0; i <= 20; i++) {
            memo[i] = 0;
            price[i] = 0;
            day[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            int due, num;
            cin >> due >> num;
            day[i] = due;
            price[i] = num;
            memo[i] = num;
        }
    }
    void solve() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (j + day[j] <= i) {
                    memo[i] = max(memo[i], price[i] + memo[j]);
                }
            }
        }
//        display();
        print();
    }
    void display() {
        for (int i = 0; i <= n; i++) {
            cout << memo[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        for (int i = 1; i <= n; i++) {
            if (i + day[i] <= n + 1) {
                ans = max(ans, memo[i]);
            }
        }
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    DP_Part3_33 DP_Part3_33;
    DP_Part3_33.solve();
    return 0;
}