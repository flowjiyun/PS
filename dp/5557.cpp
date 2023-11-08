#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;


int n;
long long memo[100][21];
int seq[100];

long long dp(int curIndex, int result) {
    if (result < 0 || result > 20) {
        return 0;
    }
    if (curIndex == n - 1) {
        if (result == seq[n - 1]) {
            return 1;
        } else {
            return 0;
        }
    }
    if (memo[curIndex][result] != -1) {
        return memo[curIndex][result];
    }

    long long ans = 0;
    ans += dp(curIndex + 1, result + seq[curIndex]);
    ans += dp(curIndex + 1, result - seq[curIndex]);
    memo[curIndex][result] = ans;
    return ans; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }
    cout << dp(1, seq[0]);


    return 0;
}
