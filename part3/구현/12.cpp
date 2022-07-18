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
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            map[i][j] = 2;
        }
    }
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int a = build_frame[i][2];
        int b = build_frame[i][3];
        if (b == 1) {       // 설치
            if (a == 0) {   // 기둥
                if (y == 0 || map[y-1][x] == 0 || map[y][x-1] == 1) {
                    map[y][x] = 0;
                }
            }
            if (a == 1) {   // 보
                if (y > 0) {
                    if (map[y-1][x] == 0 || map[y-1][x+1] == 0 || (map[y][x+1] == 1 && map[y][x-1] == 1)) {
                        map[y][x] = 1;
                    }
                }
            }
        }
        else if (b == 0) {              // 삭제
            if (a == 0) {   // 기둥
                if (x > 0) {
                    if (map[y][x-1] == 1) {     // 기둥이 보 위에 있다면
                        // 위에 기둥도 없고 보도 없어야해
                        if (map[y+1][x] == 2 && map[y][x-1] != 1) {
                            map[y][x] = 2;
                        }
                    }
                    else if (map[y+1][x] == 1) {     // 옆에 만약 보가 있다면
                        // 반대편에 보가 있는지 확인
                        if (map[y+1][x-1] == 1) {
                            map[y][x] = 2;
                        }
                    }
                    else {                      // 보가 없다면
                        // 기둥이 위에 없어야 해 확인
                        if (map[y+1][x] != 0) {
                            map[y][x] = 2;
                        }
                    }
                }
                else if (x == 0) {  // 얘는 해결된듯
                    if (map[y+1][x] == 2) {
                        map[y][x] = 2;
                    }
                }
            }
            if (a == 1) {   // 보
                // 바로 밑에 기둥이 있는 경우
                // 양 옆에 기둥이 있는 경우
                // 한쪽 만 기둥이 있는 경우
                // 양쪽이 보와 연결된 경우
                if (map[y-1][x] == 0) {     // 바로 밑에 기둥이 있는 경우
                    if (map[y][x+1] != 1 || map[y][x+2] != 1) {
                        map[y][x] = 2;
                    }
                }
                if (map[y-1][x+1] == 0 && map[y-1][x-1] == 0) {     // 양 옆에 기둥이 있는 경우
                    map[y][x] = 2;
                }
                if (map[y-1][x+1] == 0) {           // 한 쪽만 기둥이 있으면 (오른쪽)
                    if (map[y][x-1] != 1) {
                        map[y][x] = 2;
                    }
                }
                else if (map[y-1][x-1] == 0) {      // 한 쪽만 기둥이 있으면 (왼쪽) 
                    if (map[y][x+1] != 1) {
                        map[y][x] = 2;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (map[j][i] == 0) {   // 기둥
                answer.push_back({i, j, 0});
            }
            if (map[j][i] == 1) {   // 보
                answer.push_back({i, j, 1});
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> ans;
    vector<vector<int>> build_frame(8);
    build_frame = {
            {0,0,0,1},
            {2,0,0,1},
            {4,0,0,1},
            {0,1,1,1},
            {1,1,1,1},
            {2,1,1,1},
            {3,1,1,1},
            {2,0,0,0},
            {1,1,1,0},
            {2,2,0,1}
    };
    ans = solution(5, build_frame);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}