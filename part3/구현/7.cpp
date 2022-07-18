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
    string s;
    cin >> s;
    int len = s.size();
    int mid = len / 2;
    int left = 0;
    int right = 0;
    for (int i = 0; i < mid; i++) {
        left += s[i] - '0';
    }
    for (int i = mid; i < len; i++) {
        right += s[i] - '0';
    }
    if (left == right) {
        cout << "LUCKY" << endl;
    }
    else {
        cout << "READY" << endl;
    }
    return 0;
}