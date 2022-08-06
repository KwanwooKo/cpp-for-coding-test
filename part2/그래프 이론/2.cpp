#include <iostream>
#include <cstdio>
#include <stack>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int disjoint_sets[100001];
bool find_parents(int node, int cmp_node) {
    int curr = node;
    while (1) {
        if (curr == cmp_node) {
            return true;
        }
        if (disjoint_sets[curr] == curr) {
            break;
        }
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= 100000; i++) {
        disjoint_sets[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int flag, from, to;
        cin >> flag >> from >> to;
        if (from > to) 
            swap(from, to);
        // 팀 합치기
        if (flag == 0) {
            disjoint_sets[to] = from;
        }
        // 같은 팀 여부 확인
        if (flag == 1) {
            if (find_parents(from, to)) {
                cout << "YES" << endl;
            }
            else {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}