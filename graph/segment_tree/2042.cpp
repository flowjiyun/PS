#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
int n, m, k;
vector<long long> input;
vector<long long> tree;

long long createSegmentTree(int start, int end, int node) {
    if (start == end) {
        tree[node] = input[start];
        return tree[node];
    }
    int mid = (start + end) / 2;
    return tree[node] = createSegmentTree(start, mid, node * 2) + createSegmentTree(mid + 1, end, node * 2 + 1);
}

void updateTree(int start, int end, int node, int index, long long delta) {
    if (index < start || index > end) {
        return;
    }
    tree[node] += delta;
    if (start == end) {
        return;
    }
    int mid = (start + end) / 2;
    updateTree(start, mid, node * 2, index, delta);
    updateTree(mid + 1, end, node * 2 + 1, index, delta);
}

long long getRangeSum(int start, int end, int node, int left, int right) {
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    int mid = (start + end) / 2;
    return getRangeSum(start, mid, node * 2, left, right) + getRangeSum(mid + 1, end, node * 2 + 1, left, right);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    int treeHeight = (int)ceil(log2(n));
    int treeSize = (1 << (treeHeight + 1));
    tree.resize(treeSize);
    input = vector<long long>(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    createSegmentTree(0, n - 1, 1);
    for (int i = 0; i < m + k; ++i) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        if (a == 1) {
            long long delta = c - input[b - 1];
            input[b - 1] = c;
            updateTree(0, n - 1, 1, b - 1, delta);
        } else if (a == 2) {
           long long ans = getRangeSum(0, n - 1, 1, b - 1, c - 1);
           cout << ans << '\n';
        }
    }
    return 0;
}