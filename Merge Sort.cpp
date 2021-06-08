#include<iostream>
#include<algorithm>
#include <time.h>

using namespace std;

void merge(int* arr, int leftIndex, int middleIndex, int rightIndex) {
    int n1 = middleIndex - leftIndex + 1;
    int n2 = rightIndex - middleIndex;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[leftIndex + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[middleIndex + j + 1];
    }

    int currLeftIndex = 0;
    int currRightIndex = 0;
    int currArrIndex = leftIndex;

    while (currLeftIndex < n1 && currRightIndex < n2) {
        if (L[currLeftIndex] > R[currRightIndex]) {
            arr[currArrIndex] = R[currRightIndex];
            currRightIndex++;
        }
        else {
            arr[currArrIndex] = L[currLeftIndex];
            currLeftIndex++;
        }
        currArrIndex++;
    }

    for (int i = currLeftIndex; i < n1; i++) {
        arr[currArrIndex] = L[i];
        currArrIndex++;
    }
    for (int i = currRightIndex; i < n2; i++) {
        arr[currArrIndex] = R[i];
        currArrIndex++;
    }
}

void mergeSort(int* arr, int leftIndex, int rightIndex) {
    if (leftIndex >= rightIndex) return;

    int middleIndex = (rightIndex + leftIndex) / 2;

    mergeSort(arr, leftIndex, middleIndex);
    mergeSort(arr, middleIndex + 1, rightIndex);

    merge(arr, leftIndex, middleIndex, rightIndex);
}

int main() {
    srand(time(NULL));

    int testSize = 1000;
    int maxArrayLength = 1000;
    int maxIntegerValue = 1000;

    int passed = 0;
    int failed = 0;

    for (int t = 0; t < testSize; t++) {
        int arraySize = rand() % maxArrayLength + 1;

        int* a = new int[arraySize];
        int* b = new int[arraySize];

        for (int i = 0; i < arraySize; i++) {
            int num = rand() % maxIntegerValue;
            a[i] = num;
            b[i] = num;
        }

        mergeSort(a, 0, arraySize-1);
        sort(b, b + arraySize);

        bool hasPassed = true;
        for (int i = 0; i < arraySize; i++) {
            if (a[i] != b[i]) {
                hasPassed = false;
                break;
            }
        }

        if (hasPassed)
            passed++;
        else
            failed++;

        delete[]a;
        delete[]b;
    }
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;

    return 0;
}