#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)2147483647
using namespace std;
typedef long long ll;
class DP_Part3_35 {
private:
    int n, ans;
    int num2, num3, num5;
    int i2, i3, i5;
    // 최대로 될 수 있는 못생긴 수
    int memo[1001];
public:
    DP_Part3_35() {
        cin >> n;
        for (int i = 0; i <= 1000; i++) {
            memo[i] = 0;
        }
        memo[1] = true;
        i2 = i3 = i5 = 0;
        num2 = 2, num3 = 3, num5 = 5;
        memo[1] = 1;
    }
    void init() {
        for (int i = 1; i <= n; i++) {
            memo[i] = min(num2, min(num3, num5));
            if (memo[i] == num2) {
                i2++;
                num2 = memo[i2] * 2;
            }
            if (memo[i] == num3) {
                i3++;
                num3 = memo[i3] * 3;
            }
            if (memo[i] == num5) {
                i5++;
                num5 = memo[i5] * 5;
            }
        }
    }
    void solve() {
        init();
        print();
    }
    void print() {
        ans = memo[n - 1];
        cout << ans << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    DP_Part3_35 DP_Part3_35;
    DP_Part3_35.solve();
    return 0;
}