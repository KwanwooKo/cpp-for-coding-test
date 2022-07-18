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
    vector<char> alpha;
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            alpha.push_back(s[i]);
        }
        else {
            num += s[i] - '0';
        }
    }
    sort(alpha.begin(), alpha.end());
    for (int i = 0; i < alpha.size(); i++) {
        cout << alpha[i];
    }
    cout << num << endl;
    return 0;
}