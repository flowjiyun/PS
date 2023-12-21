#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

// 시간 복잡도 o(n^3)
// 모든 노드에서 특정 노드 까지의 최단거리를 찾을 수 있다

using namespace std;
int n, m;
int map[101][101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (i != j)
            {
                map[i][j] = 987654321;
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        map[a][b] = min(map[a][b], c);
    }
    for (int m = 1; m <= n; ++m)
    {
        for (int s = 1; s <= n; ++s)
        {
            for (int e = 1; e <= n; ++e)
            {
                if (map[s][e] > map[s][m] + map[m][e])
                {
                    map[s][e] = map[s][m] + map[m][e];
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (map[i][j] == 987654321)
            {
                cout << "0" << ' ';
            }
            else
            {
                cout << map[i][j] << ' ';
            }
        }
        cout << "\n";
    }
    return 0;
}