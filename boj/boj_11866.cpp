#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    queue<int> Q;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        Q.push(i);
    }
    cout << '<';
    while (!Q.empty())
    {
        for (int i = 1; i <= k; i++)
        {
            if (i % k != 0)
            {
                Q.push(Q.front());
                Q.pop();
            }
            else
            {
                cout << Q.front();
                if (Q.size() != 1)
                    cout << ',' << ' ';
                Q.pop();
            }
        }
    }
    cout << '>';
    return (0);
}