#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
class Part3_27 {
private:
    int n, m, ans;
    vector<int> arr;
    vector<int> countList;
public:
    Part3_27() {
        cin >> n >> m;
        ans = -1;
        int prev;
        cin >> prev;
        int count = 1;
        for (int i = 1; i < n; i++) {
            int num;
            cin >> num;
            if (prev != num) {
                arr.push_back(prev);
                countList.push_back(count);
                count = 1;
                prev = num;
            }
            else {
                count++;
            }
        }
        arr.push_back(prev);
        countList.push_back(count);
    }

    void parametricSearch(int start, int end, int toFind) {
        if (start > end) {
            return;
        }
        int mid = (start + end) / 2;
        if (toFind == mid) {
            for (int i = 0; i < arr.size(); i++) {
                if (toFind == arr[i]) {
                    ans = countList[i];
                    break;
                }
            }
            return;
        }
        else if (toFind > mid) {
            parametricSearch(mid + 1, end, toFind);
        }
        else {
            parametricSearch(start, mid - 1, toFind);
        }
    }
    void display() {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;
        for (int i = 0; i < countList.size(); i++) {
            cout << countList[i] << ' ';
        }
        cout << endl;
    }
    void print() {
        cout << ans << endl;
    }
    void solve() {
        parametricSearch(0, n - 1, m);
//        display();
        print();
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    Part3_27 part3_27;
    part3_27.solve();

    return 0;
}