#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int n, k;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<int> pSum(100001);
    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        while (t > 0) {
            int start, end;
            cin >> start >> end;
            // prefix sum skill
            pSum[start]++;
            pSum[end]--;
            t--;
        }
    }

    for (int i = 1; i <= 100000; ++i) {
        pSum[i] += pSum[i - 1];
    }
    int curSum = 0;
    for (int i = 0; i < k; ++i) {
        curSum += pSum[i];
    }
    int ans = curSum;
    pair<int, int> time{0, k};
    for (int i = k; i <= 100000; ++i) {
        curSum -= pSum[i - k];
        curSum += pSum[i];
        if (curSum > ans) {
            ans = curSum;
            time = {i - k + 1, i + 1};
        }
    }
    cout << time.first << ' ' << time.second;

    return 0;
}