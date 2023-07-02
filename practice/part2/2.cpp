#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;

void printarr(vector<int> d) {
    for (auto a : d) {
        cout << a << ' ';
    }
    cout << endl;
}
bool cmp(int a, int b) {
    return a > b;
}
int solution1(int m, int k, vector<int> d) {
    int count = 0;
    int ans = 0;
    for (int i = 0; i < m; i++) {
        if (count == k) {
            ans += d[1];
            count = 0;
            continue;
        }
        ans += d[0];
        count++;
    }
    return ans;
}

int solution2(int m, int k, vector<int> d) {
    int cycle = k + 1;
    int times = m / cycle;
    int surplus = m % cycle;

    int ans = 0;
    int one_cycle = d[0]*k + d[1];
    ans += one_cycle * times;
    ans += d[0] * surplus;
    return ans;
}

int main(void) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d.begin(), d.end(), cmp);

    // printarr(d);
    // int ans = solution1(m, k, d);
    int ans = solution2(m, k, d);

    cout << ans << endl;
}
