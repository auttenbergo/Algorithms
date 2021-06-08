#include<iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int partition(int* a, int left, int right) {
    int pivot = a[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (a[j] < pivot) {
            i++;
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
        }
    }
    int tmp = a[i + 1];
    a[i + 1] = a[right];
    a[right] = tmp;
    return (i + 1);

}

int randomizedPartition(int* a, int left, int right) {
    int index = left +  rand() % (right - left+1);
    int tmp = a[index];
    a[index] = a[right];
    a[right] = tmp;
    return partition(a, left, right);
}

void quicksort(int* a, int left, int right) {
    if (left >= right) return;
    int pivotIndex = randomizedPartition(a, left, right);
    quicksort(a, left, pivotIndex - 1);
    quicksort(a, pivotIndex + 1, right);
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(NULL));
    
    int testSize = 1000;
    int maxArrayLength = 10;
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

        quicksort(a, 0, arraySize - 1);
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