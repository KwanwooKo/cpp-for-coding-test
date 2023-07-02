#include <iostream>
#define endl '\n'
using namespace std;

int main(void) {
    int n, k;
    cin >> n >> k;
    int ans = 0;
    while (n != 1) {
        if (n % k == 0) {
            n /= k;
        } else {
            n--;
        }
        ans++;
    }
    cout << ans << endl;
}
