#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    
    vector<int> d(n);

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d.begin(), d.end());

    int ans = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (count >= d[i]) {
            ans++;
            count = 0;
        }
    }
    cout << ans << endl;
    return 0;
}