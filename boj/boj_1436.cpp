#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    int value = 0;
    while (true)
    {
        if (cnt == n)
            break;
        value++;
        int temp = value;
        int flag = 0;
        int isAgain = 0;
        while (true)
        {
            if (isAgain == 3 || temp == 0)
                break;
            if (temp % 10 == 6)
            {
                if (flag == 1)
                    isAgain++;
                else
                {
                   flag = 1;
                   isAgain = 1;
                }
                temp /= 10;
            }
            else
            {
                flag = 0;
                isAgain = 0;
                temp /= 10;
            }
        }
        if (isAgain == 3)
            cnt++;
    }
    cout << value;

    return (0);
}