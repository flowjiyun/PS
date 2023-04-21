#include <iostream>
#include <string>

using namespace std;

int a[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string b;
	cin >> b;
	for (int i = 0; i < b.size(); ++i)
	{
		int val = b[i] - 'a';
		++a[val];
	}
	for (int i = 0; i < 26; ++i)
		cout << a[i] << ' ';
	return (0);
}