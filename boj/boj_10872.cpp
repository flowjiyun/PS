#include <iostream>

using namespace std;
int Facto(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * Facto(n - 1);
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    cout << Facto(n);
    return (0);

}