#include <iostream>
int* quickSort(int* arr, const int& arrSz)
{
	if (arrSz < 2)
		return arr;
	int propElem = arr[0];
	size_t lessNum = 0;
	size_t greaterNum = 0;
	for (size_t i = 1; i != arrSz; ++i)
	{
		if (arr[i] <= propElem)
			++lessNum;
		else
			++greaterNum;
	}
	int* less = new int[lessNum];
	int* greater = new int[greaterNum];
	for (size_t i = 1, lessCntr = 0, greaterCntr = 0; i < arrSz; i++)
	{
		if (arr[i] <= propElem)
			less[lessCntr++] = arr[i];
		else
			greater[greaterCntr++] = arr[i];
	}
	quickSort(less, lessNum);
	quickSort(greater, greaterNum);
	size_t tempI = 0;
	for (; tempI < lessNum; ++tempI)
	{
		arr[tempI] = less[tempI];
	}
	arr[tempI++] = propElem;

	for (size_t i = 0; tempI < arrSz; ++tempI, ++i)
	{
		arr[tempI] = greater[i];
	}
	return arr;
}


int main()
{
	int arr[] = { 2,1,5,7,9};
	int arrSize = sizeof(arr) / sizeof(arr[0]);

	quickSort(arr, arrSize);

	std::cout << "Sorted array is \n";

	for (int i = 0; i < arrSize; ++i)
		std::cout << arr[i] << " ";
}