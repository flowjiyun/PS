#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string base;
	cin >> base;
	int pos;
	pos = base.find('*');
	string prev = base.substr(0, pos);
	string last = base.substr(pos + 1);
	for (int i = 0; i < n; ++i)
	{
		string file;
		cin >> file;
		if (prev.size() + last.size() > file.size())
			cout << "NE\n";
		else if (prev == file.substr(0, prev.size()) && last == file.substr(file.size() - last.size()))
			cout << "DA\n";
		else
			cout << "NE\n";
	}
	return (0);
}