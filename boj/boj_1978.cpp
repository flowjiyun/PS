//소수찾기
#include <iostream>

using namespace std;
int solve(int n)
{
    int i = 2;
    int check = 1;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            check = 0;
            break;
        }
        else
            i++;
    }
    return check;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        if (m == 1)
            continue;
        if (solve(m))
            cnt++;
    }
    cout << cnt;
    return (0);
}