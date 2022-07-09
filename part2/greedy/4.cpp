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
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (1) {
        if (n == 1) {
            break;
        }
        if (n % k == 0) {
            n /= k;
        }
        else {
            n--;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}