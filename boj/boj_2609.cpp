// 유클리드 호제법 사용
#include <iostream>

using namespace std;
int n, m;
int solve(int& a, int& b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    int r = a % b;
    if (r == 0)
        return b;
    return solve(b, r);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int g = solve(n, m);
    cout << g << '\n';
    cout << n * m / g;
    return (0);
}