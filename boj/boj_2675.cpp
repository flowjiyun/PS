#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    int R;
    string s;
    cin >> T;
    while (T--)
    {
        cin >> R >> s;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < R; j++)
                cout << s[i];
        }
        cout << '\n';
    }
    return (0);
}