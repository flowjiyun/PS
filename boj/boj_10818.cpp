#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int max = -1000001;
    int min = 1000001;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        if (max < val)
            max = val;
        if (min > val)
            min = val;
    }
    cout << min << ' ' << max;
    return (0);
}