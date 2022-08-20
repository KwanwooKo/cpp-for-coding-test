#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#define endl '\n'
#define INF (int)1e9
using namespace std;
typedef long long ll;
int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
int findNum = 2;
bool isFound = false;
void parametricSearch(int start, int mid, int end, int count) {
    if (start > mid) {
        cout << "안됨" << endl;
        return;
    }
    if (findNum == arr[mid]) {
        cout << count << endl;
        isFound = true;
        return;
    }
    else if (findNum < arr[mid]) {
        parametricSearch(start, (mid - start) / 2, mid - 1, count + 1);
    }
    else {
        parametricSearch(mid + 1, (end - mid) / 2, end, count + 1);
    }

}
int main(void) {
    parametricSearch(0, 5, 10, 0);
}