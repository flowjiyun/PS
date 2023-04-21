#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string val;
		cin >> val;
		++a[val[0] - 'a'];
	}
	int flag = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (a[i] >= 5)
		{
			cout << (char)(i + 'a');
			flag = 1;
		}
	}
	if (flag == 0)
		cout << "PREDAJA";

	return (0);
}