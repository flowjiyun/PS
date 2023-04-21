#include <iostream>
#include <vector>
#include <string>

using namespace std;


char alpha_cnt[200];
string input, ret;
char mid;
int flag;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> input;
	for (char c : input)
		++alpha_cnt[int(c)];
	for (int i = 'Z'; i >= 'A'; --i)
	{
		if (alpha_cnt[i] & 1)
		{
			mid = char(i);
			++flag;
			--alpha_cnt[i];
		}
		if (flag == 2)
			break;
		for (int j = 0; j < alpha_cnt[i]; j += 2)
		{
			ret = char(i) + ret;
			ret += char(i);
		}
	}
	if (mid)
		ret.insert(ret.begin() + ret.length() / 2, mid);
	if (flag == 2)
		cout << "I'm Sorry Hansoo";
	else
		cout << ret;
	
	return (0);
}