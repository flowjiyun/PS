#include <iostream>
#include <string>
#include <cstring>

using namespace std;

char change_upper(int c)
{
	int i;

	i = c - 'A' + 13;
	if (i < 26)
		return ((char)(i + 'A'));
	else
		return ((char)(i + 'A' - 26));
}

char change_lower(int c)
{
	int i;

	i = c - 'a' + 13;
	if (i < 26)
		return ((char)(i + 'a'));
	else
		return ((char)(i + 'a' - 26));
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string input;
	getline(cin, input);

	for (int i = 0; i < input.size(); ++i)
	{
		if (isupper(input[i]))
		{
			cout << change_upper(input[i]);
		}
		else if (islower(input[i]))
			cout << change_lower(input[i]);
		else
			cout << input[i];
	}
	return (0);
}