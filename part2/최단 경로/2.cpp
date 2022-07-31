#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 1e9
using namespace std;
typedef long long ll;
int edges[101][101];
int memo[101][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int x, k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            memo[i][j] = INF;
            edges[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edges[from][to] = 1;
        edges[to][from] = 1;
    }
    // x 가 최종 도착지, k 가 경유점
    cin >> x >> k;
    // 1 -> k -> x
    /*
        1->2 1->3 1->4 2->4 3->4 3->5 4->5

        1->5->4

        1) 1->5 가는 경로
        1->2->5
        1->3->5
        1->4->5 // 얘는 넘어가야돼

        2) 5->4 가는 경로
        5->1->4
        5->2->4
        5->3->4
        5->4
    */
    // k 를 먼저 방문 하는 최단경로
    // 1->k
    for (int i = 1; i <= n; i++) {
        edges[1][k] = min(edges[1][k], edges[1][i] + edges[i][k]);
    }
    // k->x
    for (int i = 1; i <= n; i++) {
        edges[k][x] = min(edges[k][x], edges[k][i] + edges[i][x]);
    }
    if (edges[1][k] == INF || edges[k][x] == INF) {
        cout << -1 << endl;
    }
    else {
        cout << edges[1][k] + edges[k][x] << endl;
    }

    return 0;
}