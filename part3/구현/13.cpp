#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int map[51][51];
bool check[51][51];
vector<pair<int, int>> chicken;
vector<pair<int,int>> house;
vector<pair<int, int>> chickenList;
vector<int> distList;
int ans = 2147483647;
int n, m;
void go(int count, int from) {
    if (count == m) {
        int minDist = 0;
        for (int i = 0; i < house.size(); i++) {
            int hx = house[i].first;
            int hy = house[i].second;
            int dist = 2147483647;
            for (int j = 0; j < chickenList.size(); j++) {
                int cx = chickenList[j].first;
                int cy = chickenList[j].second;
                dist = min(dist, abs(hx - cx) + abs(hy - cy));
            }
            minDist += dist;
        }
        distList.push_back(minDist);
        return;
    }
    for (int i = from; i < chicken.size(); i++) {
        int x = chicken[i].first;
        int y = chicken[i].second;
        if (check[x][y] == true) continue;
        check[x][y] = true;
        chickenList.push_back({x, y});
        go(count + 1, i + 1);
        chickenList.pop_back();
        check[x][y] = false;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) house.push_back({i, j});
            if (map[i][j] == 2) chicken.push_back({i, j});
        }
    }
    // chicken 배열, house 배열
    int from = 0;
    go(0, from);
    for (int i = 0; i < distList.size(); i++) {
        ans = min(ans, distList[i]);
    }
    cout << ans << endl;
    return 0;
}