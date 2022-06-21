#include <iostream>

using namespace std;
int solve(long long n)
{
    long long i = 2;
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
    long long n, m;
    cin >> n >> m;
    for (long long i = n; i <= m; i++)
    {
        if (i == 1)
            continue;
        if (solve(i))
            cout << i << '\n';
    }
    return (0);
}