#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    queue<int> q;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
    }
    cout << '<';
    while (!q.empty())
    {
        for (int i = 1; i <= k; i++)
        {
            if (i % k != 0)
            {
                q.push(q.front());
                q.pop();
            }
            else
            {
                cout << q.front();
                if (q.size() != 1)
                    cout << ',' << ' ';
                q.pop();
            }
        }
    }
    cout << '>';
    return (0);
}