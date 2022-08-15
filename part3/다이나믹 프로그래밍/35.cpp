#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)2147483647
using namespace std;
typedef long long ll;
class DP_Part3_35 {
private:
    int n, count, ans;
    // 최대로 될 수 있는 못생긴 수
    bool memo[2001];
public:
    DP_Part3_35() {
        cin >> n;
        for (int i = 0; i <= 2000; i++) {
            memo[i] = false;
        }
        memo[1] = true;
        count = 0;
    }
    void init() {
        for (int i = 2; i <= 2000; i++) {
            if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) {
                memo[i] = true;
            }
        }
    }
    void solve() {
        init();
        print();
    }
    void print() {
        for (int i = 1; i <= 2000; i++) {
            if (memo[i]) count++;
            if (count == n) {
                ans = i;
                break;
            }
        }
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