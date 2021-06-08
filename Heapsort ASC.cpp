#include<iostream>
#include <algorithm>
#include <time.h>

using namespace std;

void maxHeapify(int* a, int heapSize, int currentIndex) {
    int leftIndex = 2 * currentIndex + 1;
    int rightIndex = 2 * currentIndex + 2;

    int largestIndex = currentIndex;

    if (leftIndex < heapSize && a[leftIndex] >= a[currentIndex])
        largestIndex = leftIndex;
    if (rightIndex < heapSize && a[rightIndex] >= a[largestIndex])
        largestIndex = rightIndex;

    if (largestIndex == currentIndex) return;

    int tmp = a[currentIndex];
    a[currentIndex] = a[largestIndex];
    a[largestIndex] = tmp;

    maxHeapify(a, heapSize, largestIndex);
}

void buildMaxHeap(int* a, int n) {
    for (int i = n / 2; i >= 0; i--) {
        maxHeapify(a, n, i);
    }
}
void heapSort(int* heap, int heapSize) {
    for (int i = heapSize - 1; i >= 0; i--) {

        int tmp = heap[0];
        heap[0] = heap[heapSize - 1];
        heap[heapSize - 1] = tmp;

        heapSize--;
        maxHeapify(heap, heapSize, 0);
    }
}

int main() {

    int testSize = 5000;
    int maxArraySize = 50;
    int maxElementValue = 50;

    int passed = 0;
    int failed = 0;

    srand(time(NULL));
    for (int k = 0; k < testSize; k++) {
        int n = rand() % maxArraySize + 1;
        int* a = new int[n];
        int* b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = rand() % maxElementValue;
            b[i] = a[i];
        }
        buildMaxHeap(a, n);
        heapSort(a, n);
        sort(b, b + n);
        bool hasPassed = true;
        for (int i = 0; i < n; i++) {
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