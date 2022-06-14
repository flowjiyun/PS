#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int nb = 10;
    int cnt = 0;
    int curRemain = -1;
    int vis[42] = {};
    while (nb--)
    {
        int val;
        cin >> val;
        if (vis[val % 42] == 0 && curRemain != (val % 42))
        {
            curRemain = val % 42;
            vis[val % 42] = 1;
            cnt++;
        }
    }
    cout << cnt;
    return (0);
}