#include <iostream>
#include <cmath>

using namespace std;
int reverse(int& a)
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += (a % 10) * static_cast<int>(pow(10, 2 - i));
        a = a / 10;
    }
    return sum;
}
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    a = reverse(a);
    b = reverse(b);
    if (a > b)
        cout << a;
    else
        cout << b; 
    return (0);
}