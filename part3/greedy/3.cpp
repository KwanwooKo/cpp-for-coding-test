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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    
    int countZero = 0;
    bool startZero = false;
    int countOne = 0;
    bool startOne = false;
    bool changed = false;

    for (int i = 1; i < s.size(); i++) {
        if (s[i] != s[i - 1]) {
            changed = true;
            break;
        }
    }
    if (!changed) {
        cout << "0" << endl;
        return 0;
    }

    for (int i = 0; i < s.size(); i++) {
        // 1로 바꾸기
        if (s[i] == '0' && startOne == false) {
            startOne = true;
        }
        else if (s[i] == '1' && startOne == true) {
            startOne = false;
            countOne++;
        }
        // 0으로 바꾸기
        if (s[i] == '1' && startZero == false) {
            startZero = true;
        }
        else if (s[i] == '0' && startZero == true) {
            startZero = false;
            countZero++;
        }
        // 마지막 index 처리
        if (i == s.size() - 1) {
            if (s[i] == '1' && startOne == false) {
                countZero++;
            }
            if (s[i] == '0' && startZero == false) {
                countOne++;
            }
        }
    }
    cout << min(countZero, countOne) << endl;

    return 0;
}