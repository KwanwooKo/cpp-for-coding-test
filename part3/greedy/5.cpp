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

    int n, m;
    cin >> n >> m;
    vector<int> d;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        d.push_back(num);
    }
    int ans = 0;
    for (int i = 0; i < d.size(); i++) {
        for (int j = i + 1; j < d.size(); j++) {
            if (d[i] != d[j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}