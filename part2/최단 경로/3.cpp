#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF 987654321
using namespace std;
typedef long long ll;
vector<pair<int, int>> edges[30001];
int node_price[30001] = {INF, };
bool check[30001];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 30000; i++) {
        node_price[i] = INF;
    }
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 0; i < m; i++) {
        int from, to, price;
        cin >> from >> to >> price;
        edges[from].push_back({to, price});
    }
    // (비용, 노드)
    priority_queue<pair<int, int>> pq;

    pq.push({0, c});
    node_price[c] = 0;
    while (!pq.empty()) {
        int price = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (check[node]) continue;
        check[node] = true;
        for (int next = 0; next < edges[node].size(); next++) {
            if (price + edges[node][next].second < node_price[edges[node][next].first]) {
                node_price[edges[node][next].first] = price + edges[node][next].second;
                pq.push({node_price[edges[node][next].first], edges[node][next].second});
            }
        }
    }
    int city_number = 0, total_time = 0;
    for (int i = 1; i <= n; i++) {
        cout << node_price[i] << ' ';
        if (node_price[i] != INF) {
            if (i != c) {
                city_number++;
            }
            total_time = max(total_time, node_price[i]);
        }
    }
    cout << endl;
    cout << city_number << ' ' << total_time << endl;
    return 0;
}