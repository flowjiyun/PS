#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cur = 0;
    int sum = 1;
    int cnt = 1;
    if (n == 1)
    {
        cout << n;
        return (0);
    }
    while (sum <= n)
    {
        int temp_sum = sum;
        cur += 6;
        sum += cur;
        if (n > temp_sum && n <= sum)
        {
            cnt++;
            break;
        }
        else
            cnt++;
    }
    cout << cnt;
    return (0);
}
