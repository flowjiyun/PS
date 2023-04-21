#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> d1;
string d2[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string name;
	for (int i = 1; i <= n; ++i)
	{
		cin >> name;
		d1.insert({name, i});
		d2[i] = name;
	}
	string q;
	for (int i = 0; i < m; ++i)
	{
		cin >> q;
		if (atoi(q.c_str()) == 0)
			cout << d1[q] << '\n';
		else
			cout << d2[atoi(q.c_str())] << '\n';
	}
	return(0);
}