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
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                if (i % 10 == 3 || j % 10 == 3 || k % 10 == 3 || i / 10 == 3 || j / 10 == 3 || k / 10 == 3) {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}