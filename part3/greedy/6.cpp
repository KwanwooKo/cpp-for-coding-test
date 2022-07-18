#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
int solution(vector<int> food_times, ll k) {
    int answer = 0;
    vector<pair<int, int> > d;
    for (int i = 0; i < food_times.size(); i++) {
        d.push_back(make_pair(food_times[i], i + 1));
    }
    sort(d.begin(), d.end());
    int sum = 0;
    int size = food_times.size();


    return answer;
}
int main(void) {
    vector<int> food_times;
    ll k = 37;
    for (int i = 0; i < 16; i++) {
        int num;
        cin >> num;
        food_times.push_back(num);
    }

    cout << solution(food_times, k) << endl;;
    return 0;
}
