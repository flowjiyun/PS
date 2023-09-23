#include <iostream>
#include <algorithm>

using namespace std;

bool CheckSorted(int* arr, int size)
{
  for (int i = 0; i < size - 1; ++i) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }
	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	{
		int arr[] = { 8, 3, 2, 5, 1, 1, 2, 5, 8, 9 };
		int size = sizeof(arr) / sizeof(arr[0]);

		for (int i = 0; i < size - 1; i++)
		{

      int minIndex = i;
      for (int j = i + 1; j < size; ++j) {
        if (arr[minIndex] > arr[j]) {
          minIndex = j;
        }
      }
      std::swap(arr[i], arr[minIndex]);
			Print(arr, size);

			cout << boolalpha;
			cout << CheckSorted(arr, size);
			cout << endl;
		}
	}
	return 0; 
}

