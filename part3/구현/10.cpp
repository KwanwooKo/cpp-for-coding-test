#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int map[21][21];
// 모르겠다...
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    for (int i = 1; i <= lock.size(); i++) {
        for (int j = 1; j <= lock[i].size(); j++) {
            map[i][j] = lock[i][j];
        }
    }
    return answer;
}
int main(void) {

}