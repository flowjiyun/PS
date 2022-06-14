#include <iostream>
#include <string>
// 처음나오는 위치를 위한 조건 처음에 빼먹음

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int pos[26];
    for (int i = 0; i < 26; i++)
        pos[i] = -1;
    string word;
    cin >> word;
    for (int i = 0; i < word.size(); i++)
    {
        if (pos[word[i] - 'a'] == -1) // 첫등장위치
            pos[word[i] - 'a'] = i;
    }
    for (int i = 0; i < 26; i++)
        cout << pos[i] << ' ';
    return (0);
}