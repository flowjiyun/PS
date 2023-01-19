#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
// 문자열 뒤집기
// 문자열 비교하기
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string origin;
	string reversed;
	cin >> origin;
	reversed = origin;
	reverse(reversed.begin(), reversed.end());
	if (origin.compare(reversed) == 0)
		cout << 1;
	else
		cout << 0;
	return (0);
}