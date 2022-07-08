// average : 평균이 음수일 때와 양수일때를 주의해서 해결필요
// 중앙값 : 입력값이 홀수이므로 전체 입력 길이의 반을 출력
// 최빈값 : map이용하여 입력값의 빈도수 구하고 빈도수의 최대값을 구하고 최대값이 여러개일 수 있기 때문에
//        최대값을 가지는 입력값을 차례로 벡터에 담아 조건에 맞게 출력 (map은 기본적으로 정렬을 해줌을 이용)
// 범위 : 정렬된 입력 값의 마지막에서 처음을 뺌
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int	Average(vector<int> input)
{
	double sum = 0;
	for (auto i = input.begin(); i != input.end(); i++)
	{
		sum += *i;
	}
	double result = sum / input.size();
	if (result >= 0)
		return static_cast<int>(result + 0.5);
	else	
		return static_cast<int>(result - 0.5);
}

int	Mid(vector<int> input)
{
	int idx = input.size() / 2;
	return input[idx];
}

int	GetMost(vector<int> input)
{
	map<int , int> freq;
	vector<int> ans;
	for (auto i = input.begin(); i != input.end(); i++)
	{
		freq[*i]++;
	}
	int max = 0;
	for (auto i = freq.begin(); i != freq.end(); i++)
	{
		if (max < (*i).second)
		{
			max = (*i).second;
		}
	}
	for (auto i = freq.begin(); i != freq.end(); i++)
	{
		if ((*i).second == max)
		{
			ans.push_back((*i).first);			
		}
	}
	if (ans.size() > 1)
		return ans[1];
	else
		return ans[0];
}

int GetRange(vector<int> input)
{
	return input[input.size() - 1] - input[0];
}

int	main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> input;
	int n;
	cin >> n;
	while (n--)
	{
		int val;
		cin >> val;
		input.push_back(val);
	}
	sort(input.begin(), input.end());
	cout << Average(input) << '\n';
	cout << Mid(input) <<  '\n';
	cout << GetMost(input) << '\n';
	cout << GetRange(input);
	return (0);
}