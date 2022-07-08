#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        d.push_back(num);
    }
    sort(d.begin(), d.end());
    int sum = 0;
    int mod = m % k;
    int div = m / k;
    sum = d[n - 1] * div * k + d[n - 2] * mod;
    cout << sum << endl;
    return 0;
}
