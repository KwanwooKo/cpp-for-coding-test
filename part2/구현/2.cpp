#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int dx[] = {2, -2, -2, 2, 1, 1, -1, -2};
int dy[] = {1, -1, 1, -1, 2, -2, 2, -1};
int main(void) {
    string s;
    cin >> s;
    int x = s[1] - '0';
    int y = s[0] - 'a' + 1;
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || ny < 1 || nx > 8 || ny > 8) {
            continue;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}