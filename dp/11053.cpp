#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> memo(1001, -1);
vector<int> seq(1001);

int dp(int i) {
    if (memo[i] != -1) {
        return memo[i];
    }
    int ans = 1;
    for (int j = 0; j < i; ++j) {
        if (seq[j] < seq[i]) {
            ans = max(ans, dp(j) + 1);
        }
    }
    memo[i] = ans;
    return ans; 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp(i));
    }
    cout << ans;
    return 0;
}