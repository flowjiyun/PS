// 특별한 규칙을 찾기 여려워 브루트포스 사용
#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cur = 0;
    int ans = 0;
    while (cur < n)
    {
        int temp = cur;
        int sum = temp;
        while (temp > 0)
        {
            sum +=  temp % 10;
            temp /= 10;
        }
        if (sum == n)
        {
            ans = cur;
            break;
        }
        cur++;
    }
    if (ans)
        cout << ans;
    else 
        cout << 0;
    return (0);
}