#include<iostream>
#include <algorithm>
#include <time.h>

using namespace std;

int maxElem(int* a, int n) {
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > k) k = a[i];
    }
    return k;
}
void fillArrayWithZeros(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}
void calculateFrequencies(int* a, int* c, int n) {
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }
}
void translateToPrefixSum(int* a, int n) {
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
}
void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void countingSort(int* a, int* b, int n) {
    int k = maxElem(a, n) + 1;
    int* c = new int[k];
    fillArrayWithZeros(c, k);
    calculateFrequencies(a, c, n);
    translateToPrefixSum(c, k);
    //printArray(c,k);
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
    delete[]c;

}

int main() {


    srand(time(NULL));
    int testSize = 10000;
    int maxArraySize = 10;
    int maxElemValue = 10;
    int passed = 0;
    int failed = 0;
    for (int t = 0; t < testSize; t++) {
        int arraySize = rand() % maxArraySize;
        int* a = new int[arraySize];
        int* b = new int[arraySize];
        for (int i = 0; i < arraySize; i++) {
            a[i] = rand() % maxElemValue;
        }

        countingSort(a, b, arraySize);
        sort(a, a + arraySize);

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