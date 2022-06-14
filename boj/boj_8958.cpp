#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int score = 0;
        int sum = 0;
        string s;
        int flag = 1;
        cin >> s;
        for (auto &c : s)
        {
            if (c == 'O' && flag)
            {
                score++;
                sum += score;
            }
            else if (c == 'O' && !flag)
            {
                score = 1;
                flag = 1;
                sum += score;
            }
            else if (c == 'X')
            {
                flag = 0;
            }
        }
        cout << sum << '\n';
    }
    return (0);
}