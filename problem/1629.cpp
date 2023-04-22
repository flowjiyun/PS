#include <iostream>

using namespace std;
long long a, b, c, ans;

long long solve(long long a, long long b, long long c)
{
	long long ret;
	// base condition
	if (b == 1)
		return a % c;
	ret = solve(a, b / 2, c);
	ret = ret * ret % c;
	if (b % 2 != 0)
		ret = ret * a % c;
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> a >> b >> c;
	ans = solve(a, b, c);	
	cout << ans;
	return (0);
}