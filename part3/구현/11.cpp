#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int map[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int main(void) {
    int n, k, l;
    int x = 1, y = 1;       // 머리좌표
    map[1][1] = 2;          // 뱀: 2
    int dir = 0;           // 동: 0, 북: 1, 서: 2, 남: 3 (머리 기준 방향)
    cin >> n;
    cin >> k;
    int len = 1;
    int count = 0;
    for (int i = 0; i < k; i++) {
        int row, col;
        cin >> row >> col;
        map[row][col] = 1;
    }
    cin >> l;
    queue<pair<int, char>> q;
    deque<pair<int, int>> dq;
    dq.push_back({1, 1});
    for (int i = 0; i < l; i++) {
        int time;
        char order;
        cin >> time >> order;
        q.push({time, order});
    }
    while (1) {
       cout << count << "초후 상황" << endl;
       for (int i = 1; i <= n; i++) {
           for (int j = 1; j <= n; j++) {
               cout << map[i][j] << ' ';
           }
           cout << endl;
       }
        int bx = x;
        int by = y;
        x += dx[dir];
        y += dy[dir];
        int tx = dq.front().first;
        int ty = dq.front().second;
        count++;
        if (map[x][y] == 2 || x < 1 || y < 1 || x > n || y > n) {   // 게임 종료
            break;
        }
        if (map[x][y] == 1) {
            map[x][y] = 2;
            dq.push_back({x, y});
            len++;
        }
        else if (map[x][y] == 0) {
            map[x][y] = 2;
            map[tx][ty] = 0;
            dq.push_back({x, y});
            dq.pop_front();
        }
        if (!q.empty()) {
            int time = q.front().first;
            char order = q.front().second;
            if (count == time) {
                q.pop();
                if (order == 'L') dir++;
                else if (order == 'D') dir--;
                if (dir == -1) dir = 3;
                if (dir == 4) dir = 0;
            }
        }
    }
    cout << count << endl;
    return 0;
}