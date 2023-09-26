#include <iostream>
#include <cassert>

using namespace std;

void InsertionSort(char* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key) // <- while 사용
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

int Count(char* arr, int n, char x)
{
	int count = 0;
	for (int i = 0; i < n; i++) // start index 사용
	{
		if (arr[i] == x)
			count++;
	}

	return count;
}

int main()
{
	char arr[] = "ababcdfdceeedag";
	int n = sizeof(arr) - 1;

	assert(n >= 1);

	cout << arr << endl;

	int table[26] = { 0 }; // 모든 값을 0으로 초기화
  for (int i = 0; i < n; ++i) {
    table[arr[i] - 97]++;
  }
	for (int i = 0; i < 26; i++)
	{
    if (table[i] != 0) {
      cout << (char)(i + 97) << table[i];
    }
	}

	cout << endl;

	cout << endl << endl;

	// 풀이 2. 정렬 후 찾기

	InsertionSort(arr, n);

	cout << arr << endl;

	char c = arr[0];
	int count = 1;

	cout << c;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] == c)
		{
      count++;
		}
		else
		{ 
      cout << count;
      cout << arr[i];
      c = arr[i];
      count = 1;
		}
	}

	cout << count << endl; // 마지막 count 출력

	return 0;
}