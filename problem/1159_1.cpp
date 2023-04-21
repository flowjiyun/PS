
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a[26];
// string 사용법
// 1. + 연산자를 통행 문자를 뒤에 추가 할 수 있다
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
	string ret;
	for (int i = 0; i < 26; ++i)
	{
		if (a[i] >= 5)
			ret += (i + 'a');
	}
	if (ret.size())
		cout << ret;
	else
		cout << "PREDAJA";

	return (0);
}