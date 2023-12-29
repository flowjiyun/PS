#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> memo;

int t;
int dp(int tileCol, int state) {
    if (tileCol < 0) {
        return 0;
    }
    if (tileCol == 0) {
        if (state == 0) {
            return 1;
        } else {
            return 0;
        }
    }
    int &ret = memo[tileCol][state];
    if (ret != -1) {
        return ret;
    }

    ret = 0;
    switch (state) {
        case 0:
            ret = dp(tileCol - 1, 0) + dp(tileCol - 2, 0) + dp(tileCol - 1, 1) + dp(tileCol - 1, 2) + dp(tileCol - 1, 3);
            break;
        case 1:
            ret = dp(tileCol - 1, 0) + dp(tileCol - 1, 2);
            break;
        case 2:
            ret = dp(tileCol - 1, 0) + dp(tileCol - 1, 1);
            break;
        case 3:
            ret = dp(tileCol - 1, 0) + dp(tileCol - 1, 4);
            break;
        case 4:
            ret = dp(tileCol - 1, 3);
            break;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    memo = vector<vector<int>>(500, vector<int>(5, -1));
    while (t--) {
        int n;
        cin >> n;
        cout << dp(n, 0) << '\n';
    }
    return 0;
}