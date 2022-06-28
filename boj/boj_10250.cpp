#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int h, w, n;
        cin >> h >> w >> n;
        if (n % h == 0)
            cout << h;
        else
            cout << n % h;
        if (n / h < 9)
        {
            if (n / h == 0)
                cout << "01" << '\n';
            else if (n % h == 0)
                cout << '0' << n / h << '\n';
            else
                cout << '0' << n / h + 1 << '\n';

        }
        else if (n / h == 9)
        {
            if (n % h == 0)
                cout << '0' << n / h << '\n';
            else
                cout <<  n / h + 1 << '\n';

        }
        else
        {
            if (n % h == 0)
                cout << n / h << '\n';
            else
                cout <<  n / h + 1 << '\n';
        }
    }

    return (0);
}