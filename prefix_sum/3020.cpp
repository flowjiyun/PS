#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>

using namespace std;

int n, h;
int top[500000];
int bottom[500000];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h;
    int minSum = numeric_limits<int>::max();
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        // odd
        if (i & 1) {
            top[val - 1]++;
        } else {
            bottom[h - val]++;
        }
    }
    // print
    // for (int i = 0; i < h; ++i) {
    //         cout << space[i] << ' ';
    // }
    for (int i = 1; i < h; ++i) {
        top[h - 1 - i] += top[h - i];
        bottom[i] += bottom[i - 1];
    }
    for (int i = 0; i < h; ++i) {
        int curSum = top[i] + bottom[i];
        minSum = min(minSum, curSum);
        cnt[curSum]++;
    }
    cout << minSum << ' ' << cnt[minSum];
    return 0;
}