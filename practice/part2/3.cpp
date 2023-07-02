#include <iostream>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
int board[101][101];
int main(void) {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    int ans = -1;
    for (int i = 1; i <= n; i++) {
        int min_result = 10000;
        for (int j = 1; j <= m; j++) {
            min_result = min(min_result, board[i][j]);
        }
        ans = max(ans, min_result);
    }

    
    cout << ans << endl;
}
