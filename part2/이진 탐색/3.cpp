#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ2805 {
private:
    ll n, m, max_len, sum, ans;
    vector<ll> arr;
public:
    BOJ2805() {
        cin >> n >> m;
        max_len = 0;
        sum = 0;
        for (int i = 0; i < n; i++) {
            ll num;
            cin >> num;
            arr.push_back(num);
            if (max_len < num) {
                max_len = num;
            }
        }
    }
    // 10 15 17 20
    void solve() {
        parametricSearch(0, max_len);
        cout << ans << endl;
    }
    void check(ll cutLen) {
        for (int i = 0; i < n; i++) {
            if (arr[i] - cutLen >= 0) {
                sum += arr[i] - cutLen;
            }
        }
    }
    void parametricSearch(ll start, ll end) {
        if (start > end) {
            return;
        }
        ll mid = (start + end) / 2;
        sum = 0;
        check(mid);
        if (sum == m) {
            ans = mid;
            return;
        }
        else if (sum > m) {
            ans = mid;
            parametricSearch(mid + 1, end);
        }
        else {
            parametricSearch(start, mid - 1);
        }
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2805 boj;
    boj.solve();

    return 0;
}