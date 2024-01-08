#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int MAX_VAL = 1000000000;

int memo[50][2][2][2];

int dp(vector<vector<int>>& agentInfo, int n, int index, int a, int b, int c) {
    if (index == n) {
        if (a == 1 && b == 1 && c == 1) {
            return 0;
        } else {
            return MAX_VAL;
        }
    }

    int& result = memo[index][a][b][c];

    if (result != -1) {
        return result;
    }

    result = MAX_VAL;
    result = min(result, agentInfo[index][0] + agentInfo[index][1] + dp(agentInfo, n, index + 1, a, b, true));
    result = min(result, agentInfo[index][0] + agentInfo[index][2] + dp(agentInfo, n, index + 1, a, true, c));
    result = min(result, agentInfo[index][1] + agentInfo[index][2] + dp(agentInfo, n, index + 1, true, b, c));

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case) {
        vector<vector<int>> agentInfo;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            int a, b, c;
            cin >> a >> b >> c;
            agentInfo.push_back({a, b, c});
        }
        if (n < 3) {
            cout << "#" << test_case << " " << -1 << "\n";
            continue;
        }
        fill_n(&memo[0][0][0][0], 400, -1);
        cout << "#" << test_case << " " << dp(agentInfo, n, 0, 0, 0, 0) << "\n";
    }

    return 0;
}