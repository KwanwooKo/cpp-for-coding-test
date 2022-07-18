#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        d.push_back(num);
    }
    sort(d.begin(), d.end());
    int ans = 1;
    for (int i = 0; i < d.size(); i++) {
        if (ans < d[i]) {
            break;
        }
        ans += d[i];
    }
    cout << ans << endl;
    return 0;
}