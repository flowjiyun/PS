#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    while (n >= 0)
    {
        if (n % 5 == 0)
        {
            cnt += n / 5;
            cout << cnt;
            return (0);
        }
        n = n - 3;
        cnt++;
    }
    cout << -1;
    return (0);
}