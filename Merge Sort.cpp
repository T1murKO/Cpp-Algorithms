#include <iostream>
#include <time.h>

using namespace std;

const int SIZE = 10;

void Merge(int* arr, int first, int last)
{
	int* tempArr = new int[SIZE + 1];

	int middle = (first + last) / 2;
	int start = first;
	int final = middle + 1;

	for (int i = first; i <= last; ++i)
		if ((start <= middle) && ((final > last) || (arr[start] < arr[final])))
		{
			tempArr[i] = arr[start];
			start++;
		}
		else
		{
			tempArr[i] = arr[final];
			final++;
		}

	for (int i = first; i <= last; ++i)
		arr[i] = tempArr[i];

	delete[]tempArr;
}

void MergeSort(int* arr, int firstIndex, int lastIndex)
{
	if (firstIndex < lastIndex)
	{
		MergeSort(arr, firstIndex, (firstIndex + lastIndex) / 2);
		MergeSort(arr, (firstIndex + lastIndex) / 2 + 1, lastIndex);
		Merge(arr, firstIndex, lastIndex);
	}
}

int main()
{
	srand(time(0));
	int* arr = new int[SIZE + 1];

	cout << "Random fomed array: \n";
	for (int i = 1; i <= SIZE; i++)
		arr[i] = rand() % 10 + 1;

	for (int i = 1; i <= SIZE; i++)
		cout << arr[i] << " ";



	MergeSort(arr, 1, SIZE);

	cout << "\n\n Sorted array: \n";

	for (int i = 1; i <= SIZE; i++)
		cout << arr[i] << " ";

	delete[]arr;
	return 0;
}