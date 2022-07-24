#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#define count _count
#define endl '\n'
using namespace std;
vector<int> edges[300001];
bool check[300001];
int count[300001];
vector<int> ans;
int n, m, k, x;
int main(void) { 
    /*  dfs 가 안됨
     *  4 4 2 1
     *  1 2
     *  1 3
     *  2 3
     *  2 4
     *  이렇게 했을 때 dfs 를 사용하게 되면 최단거리를 구할 수가 없다.
     *  (1->3 의 최단거리는 1이지만 dfs 일 때는 2이다)
     */ 
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(to);
    }
    queue<int> q;
    q.push(x);
    check[x] = true;
    count[x] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int next : edges[node]) {
            if (check[next]) continue;
            count[next] = count[node] + 1;
            check[next] = true;
            q.push(next);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (count[i] == k) {
            ans.push_back(i);
        }
    }
    if (ans.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
