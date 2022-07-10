//처음 생각일단 재귀함수 쓸 수 있지 않을까?

#include <iostream>

using namespace std;
int recursion(int n, int k)
{
    if (n == 0)
    {
        return k;
    }
    int sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum += recursion(n - 1, i);
    }
    return sum;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << recursion(n, k) << '\n';
    }
    return (0);
}