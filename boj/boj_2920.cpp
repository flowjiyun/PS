#include <iostream>
#include <stack>


using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[8];
    int flag_a = 0;
    int flag_d = 0;
    for (int i = 0; i < 8; i++)
    {
        cin >> arr[i];
    } 
    for (int i = 0; i < 7; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            flag_a++;
        }
        else if(arr[i] > arr[i + 1])
        {
            flag_d++;
        }
    }
    if (flag_a && !flag_d)
        cout << "ascending";
    else if (!flag_a && flag_d)
        cout << "descending";
    else
        cout << "mixed";
    return (0);
}