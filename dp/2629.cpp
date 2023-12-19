#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
vector<int> ball;
vector<vector<int>> memo;

// memo[3][1500]
// 1 2 3
void dp(int cnt, int val) {
    if (cnt > n) {
        return;
    }
    if (memo[cnt][val]) {
        return;
    }
    memo[cnt][val] = 1;
    dp(cnt + 1, val + ball[cnt]);
    dp(cnt + 1, abs(val - ball[cnt]));
    dp(cnt + 1, val);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    ball = vector<int>(n + 1, 0);
    memo = vector<vector<int>>(n + 1, vector<int>(1501, 0));
    for (int i = 0; i < n; ++i) {
        cin >> ball[i];
    }
    dp(0, 0);
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        if (val > 1500) {
            cout << "N";
        } else if (memo[n][val]) {
            cout << "Y";
        } else {
            cout << "N";
        }
        cout << " ";
    }
    return 0;
}