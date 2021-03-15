#include <iostream>
using namespace std;

void insertionSort(int arr[], const int& size)
{
	int key;
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArr(int arr[], const int& size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

int main()
{

	int arr[] = { 3,5,5,-1,9,1,0,-3,8,11 };
	int size = sizeof(arr) / sizeof(int);
	cout << "Default arr: \n";
	printArr(arr, size);

	insertionSort(arr, size);

	cout << "Sorted arr: \n";
	printArr(arr, size);

	return 0;
}
