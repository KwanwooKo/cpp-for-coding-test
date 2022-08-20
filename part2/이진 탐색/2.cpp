#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class BOJ1920 {
private:
    int n, m;
    vector<int> arr;
public:
    BOJ1920() {
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
    }
    void solve() {
        cin >> m;
        for (int i = 0; i < m; i++) {
            int num;
            cin >> num;
            parametricSearch(0, n - 1, num);
        }
    }
    void parametricSearch(int start, int end, int toFind) {
        if (start > end) {
            cout << 0 << endl;
            return;
        }
        int mid = (start + end) / 2;
        if (toFind == arr[mid]) {
            cout << 1 << endl;
            return;
        }
        else if (toFind < arr[mid]) {
            parametricSearch(start, mid - 1, toFind);
        }
        else {
            parametricSearch(mid + 1, end, toFind);
        }

    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    BOJ1920 boj;
    boj.solve();

    return 0;
}