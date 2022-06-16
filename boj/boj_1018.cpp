#include <iostream>
#include <string>
// 맨위 b 일때 번갈아 가면서 맞는지 확인 안맞으면 cnt++
using namespace std;
string board[50];
char ans[50][50];
int check_board(int r, int c)
{
    char init = board[r][c];
    int check = (r + c) % 2;
    
    int cnt = 0;
    int cnt2 = 0;
    for (int i = r; i < r + 8; i++)
    {
        for (int j = c; j < c + 8; j++)
        {
            if ((i + j) % 2 == check && board[i][j] != init)
                cnt++;
            if ((i + j) % 2 != check && board[i][j] == init)
                cnt++;
            if ((i + j) % 2 == check && board[i][j] == init)
                cnt2++;
            if ((i + j) % 2 != check && board[i][j] != init)
                cnt2++;
        }
    }
    if (cnt > cnt2)
        return cnt2;
    else
        return cnt;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    int min = 300;
    int ans = 0;
    for (int i = 0; i < n - 8 + 1; i++)
    {
        for (int j = 0; j < m - 8 + 1; j++)
        {
           ans = check_board(i, j);
           if (min > ans)
           {
               min = ans;
           }
        }
    }
    cout << min;
    return (0);
}