#include <iostream>

using namespace std;
int card[100];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> card[i];
    }
    int mx = 10;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            for (int k = 0; k < n; k++)
            {
                if (j == k || i == k)
                    continue;
                if (card[i] + card[j] + card[k] <= m)
                {
                    ans = card[i] + card[j] + card[k];
                    if (mx < ans)
                    {
                        //cout << i << j << k << '\n';
                        mx = ans;
                    }
                }
            }
        }
    }
    cout << mx; 
    return (0);
}