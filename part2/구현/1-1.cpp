#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;
typedef long long ll;
int main(void) {
    int n;
    cin >> n;
    int x = 1, y = 1;
    char c;
    while (cin >> c) {
        if (c == 'L') {
            if (y != 1) {
                y--;
            }
        }
        else if (c == 'R') {
            if (y != n) {
                y++;
            }
        }
        else if (c == 'U') {
            if (x != 1) {
                x--;
            }
        }
        else if (c == 'D') {
            if (x != n) {
                x++;
            }
        }
    }
    cout << x << ' ' << y << endl;
    return 0;
}