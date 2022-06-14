#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string word;
    cin >> word;
    int cnt[26] = {};
    for (int i = 0; i < word.size(); i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
            word[i] -= 32;
    }
    for (int i = 0; i < word.size(); i++)
    {
        int a = word[i] - 'A';
        cnt[a]++;
    }
    int max = 0;
    int max_index = 0;
    for (int i = 0; i < 26; i++)
    {
        if (max < cnt[i])
        {
            max = cnt[i];
            max_index = i;
        }
    }
    char result = 'A' + max_index;
    int IsAgain = 0;
    for (int i = 0; i < 25; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (cnt[i] != 0 && cnt[i] == cnt[j] && cnt[i] == max)
            {
                IsAgain = 1;
                break;
            }
        }
    }
    if (IsAgain)
        cout << '?';
    else
    {
        cout << result;
    }
    return (0);
}