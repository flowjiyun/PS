#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

vector<int> maxMoney;
string statusList;

int getStatusMaxMoney(int index) {
    if (statusList[index] == 'B') {
        return maxMoney[0] - 1;
    } else if (statusList[index] == 'S') {
        return maxMoney[1] - 1;
    } else if (statusList[index] == 'G') {
        return maxMoney[2] - 1;
    } else if (statusList[index] == 'P') {
        return maxMoney[3] - 1;
    } else {
        return maxMoney[3];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < 4; ++i) {
        int val;
        cin >> val;
        maxMoney.push_back(val);
    }
    cin >> statusList;
    vector<int> dp(n, 0);
    int preVal = 0;
    for (int i = 0; i < n; ++i) {
       int curMaxVal = getStatusMaxMoney(i);
       int nextMaxVal;
       if (i != n - 1) {
        nextMaxVal = getStatusMaxMoney(i + 1);
       } else {
        nextMaxVal = std::numeric_limits<int>::max();;
       }
       if (curMaxVal <= nextMaxVal) {
        if (statusList[i] != 'D') {
            dp[i] = curMaxVal - preVal;
        } else {
            dp[i] = curMaxVal;
        }
        preVal = dp[i];
       } else {
        if (statusList[i] != 'D') {
            if (curMaxVal - preVal <= nextMaxVal) {
                dp[i] = curMaxVal - preVal;
            } else {
                dp[i] = nextMaxVal;
            }
        } else {
            dp[i] = nextMaxVal;
        }
        preVal = dp[i];
       }
    }
    int ans = 0;
    for (auto val : dp) {
        // cout << val << ' ';
        ans += val;
    }
    // cout << endl;
    cout << ans;
    return 0;
}