#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class Part3_28 {
private:
    int n, ans;
    vector<int> arr;
public:
    Part3_28() {
        cin >> n;
        ans = -1;
        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            arr.push_back(num);
        }
    }
    void parametricSearch(int start, int end) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        if (mid == arr[mid]) {
            ans = mid;
            return;
        }
        else if (arr[mid] < mid) {
            parametricSearch(mid + 1, end);
        }
        else {
            parametricSearch(start, mid - 1);
        }
    }
    void print() {
        cout << ans << endl;
    }
    void solve() {
        parametricSearch(0, n - 1);
        print();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Part3_28 part3_28;
    part3_28.solve();
    return 0;
}