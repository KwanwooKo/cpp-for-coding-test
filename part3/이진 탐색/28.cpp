#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ2110 {
private:
    int n, c, minNum, maxNum, ans;
    vector<int> wifi;
public:
    BOJ2110() {
        cin >> n >> c;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            wifi.push_back(num);
        }
        sort(wifi.begin(), wifi.end());
        minNum = 1;
        maxNum = wifi[n - 1] - wifi[0];
    }
    void print() {
        cout << ans << endl;
    }
    void solve() {
        int start = minNum;
        int last = maxNum;
        while (start <= last) {
            int mid = (start + last) / 2;
            int cmp = wifi[0];
            int count = 1;
            for (int i = 1; i < n; i++) {
                if (wifi[i] - cmp >= mid) {
                    cmp = wifi[i];
                    count++;
                }
            }
            if (count >= c) {
                ans = mid;
                start = mid + 1;
            }
            else {
                last = mid - 1;
            }
        }
        print();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ2110 boj;
    boj.solve();

    return 0;
}