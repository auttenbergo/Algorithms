#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;


void sortASC(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int currentElement = arr[i];
		int prevIndex = i - 1;
		while (prevIndex >= 0 && arr[prevIndex] > currentElement) {
			arr[prevIndex + 1] = arr[prevIndex];
			prevIndex--;
		}
		arr[prevIndex + 1] = currentElement;
	}
}
void sortDESC(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int currentElement = arr[i];
		int prevIndex = i - 1;
		while (prevIndex >= 0 && arr[prevIndex] < currentElement) {
			arr[prevIndex + 1] = arr[prevIndex];
			prevIndex--;
		}
		arr[prevIndex + 1] = currentElement;
	}
}
void printArray(int* arr,int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void testSorting() {
	srand(time(NULL));

	int testSize = 2500;
	int maxArrayLength = 1000;
	int maxIntegerValue = 1000;

	int passed = 0;
	int failed = 0;

	for (int t = 0; t < testSize; t++) {
		/* Init */
		int arraySize = rand() % maxArrayLength + 1;

		int* testArrayASC = new int[arraySize];
		int* testArrayDESC = new int[arraySize];

		int* expectedArrayASC = new int[arraySize];
		int* expectedArrayDESC = new int[arraySize];

		for (int i = 0; i < arraySize; i++) {
			int num = rand() % maxIntegerValue;
			testArrayASC[i] = num;
			testArrayDESC[i] = num;
			expectedArrayASC[i] = num;
			expectedArrayDESC[i] = num;

		}
		/* Sort */
		sortASC(testArrayASC, arraySize);
		sort(expectedArrayASC, expectedArrayASC + arraySize);

		sortDESC(testArrayDESC, arraySize);
		sort(expectedArrayDESC, expectedArrayDESC + arraySize, greater<int>());

		/* Check */
		bool hasPassed = true;
		for (int i = 0; i < arraySize; i++) {
			if (testArrayASC[i] != expectedArrayASC[i])
				hasPassed = false;
		}
		for (int i = 0; i < arraySize; i++) {
			if (testArrayDESC[i] != expectedArrayDESC[i])
				hasPassed = false;
		}

		if (hasPassed)
			passed++;
		else
			failed++;

		delete []testArrayASC;
		delete []testArrayDESC;
		delete []expectedArrayASC;
		delete []expectedArrayDESC;
	}
	cout << "Passed: " << passed << endl;
	cout << "Failed: " << failed << endl;
}

void clientVersion() {
	/* Length and values */
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		int num; cin >> num; arr[i] = num;
	}
	sortASC(arr, n);
	printArray(arr, n);
	sortDESC(arr, n);
	printArray(arr, n);

	/* Free the memory */
	delete []arr;
}

int main()
{
	testSorting();
	return 0;
}
