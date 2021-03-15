void SelectionSort(int* arr, int size, bool(*ComparisonFunc)(int, int)) {
	for (int startID = 0; startID < size - 1; startID++) {
		int bestID = startID;
		for (int CurrentID = startID + 1; CurrentID < size; CurrentID++) {
			if (ComparisonFunc(arr[bestID], arr[CurrentID]))
				bestID = CurrentID;
		}
		swap2(arr[bestID], arr[startID]);
	}
}
bool ascending(int a, int b) {
	return a > b;
}
bool descending(int a, int b) {
	return a < b;
}