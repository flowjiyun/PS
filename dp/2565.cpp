#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int n;
vector<pair<int, int>> lines;
vector<int> memo(101, -1);

int dp(int i) {
    if (memo[i] != -1) {
        return memo[i];
    }
    int ans = 1;
    for (int j = 0; j < i; ++j) {
        if (lines[j].second < lines[i].second) {
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
        int from, to;
        cin >> from >> to;
        lines.push_back({from, to});
    }

    sort(lines.begin(), lines.end());

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, dp(i));
    }
    cout << n - ans;
    return 0;
}