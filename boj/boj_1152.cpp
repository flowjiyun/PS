//단어의 갯수
#include <iostream>
#include <string>

using namespace std;
char arr[1000001];
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string line;
    getline(cin, line);

    if (line.empty())
    {
        cout << 0;
        return (0);
    }
    int cnt = 1;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ' ')
        {
            cnt++;
        }
    }
    if (line[0] == ' ')
        cnt--;
    if (line[line.length() - 1] == ' ')
        cnt--;
    cout << cnt;
    return 0;

}