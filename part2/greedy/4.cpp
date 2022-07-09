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
        else if (n == 0) {  
            // 나머지를 뺄 때 n < k 인 경우 0이 돼기 때문에 1을 빼준다.
            ans--;
            break;
        }
        if (n % k == 0) {
            n /= k;
            ans++;
        }
        else {
            int mod = n % k;
            n -= mod;
            ans += mod;
        }
    }
    cout << ans << endl;
    return 0;
}