#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n;
int mod = 1000000;
int memo[1001][1001][2][3];
int dp(int i, int go, int late, int absent) {
    if (late == 2 || absent == 3) {
        return 0;
    }
    if (i == n) {
        return 1;
    }
    if (memo[i][go][late][absent] != -1) {
        return memo[i][go][late][absent];
    }
    memo[i][go][late][absent] = dp(i + 1, go + 1, late, 0) + 
                                dp(i + 1, go, late + 1, 0) + 
                                dp(i + 1, go, late, absent + 1);
    memo[i][go][late][absent] %= mod;
    return memo[i][go][late][absent];
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    memset(memo, -1, sizeof(memo));
    cout << dp(0, 0, 0, 0);
    return 0;
}