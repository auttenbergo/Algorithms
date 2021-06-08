#include<iostream>
#include<algorithm>
#include <time.h>

using namespace std;

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int getMax(int* a, int n) {
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
void calculateFrequencies(int* a, int c[], int n, int place) {
    for (int i = 0; i < n; i++) {
        int index = (a[i] / place) % 10;
        c[index]++;
    }
}
void translateToPrefixSum(int* a, int n) {
    for (int i = 1; i < n; i++) {
        a[i] += a[i - 1];
    }
}
void copyArray(int from[], int to[], int n) {
    for (int i = 0; i < n; i++) {
        to[i] = from[i];
    }
}
void countingSort(int* a, int n, int place) {
    int c[10];
    int* b = new int[n];
    fillArrayWithZeros(c, 10);
    calculateFrequencies(a, c, n, place);
    translateToPrefixSum(c, 10);
    for (int i = n - 1; i >= 0; i--) {
        int index = (a[i] / place) % 10;
        b[c[index] - 1] = a[i];
        c[index]--;
    }
    copyArray(b, a, n);
    
    delete[]b;
}


void radixSort(int* a, int n) {
    int max = getMax(a, n);
    for (int place = 1; max / place > 0; place *= 10) {
        countingSort(a, n, place);
    }
}



int main() {
    srand(time(NULL));
    int testSize = 1000;
    int maxArraySize = 100;
    int maxElementSize = INT_MAX;

    int passed = 0;
    int failed = 0;

    for (int test = 0; test < testSize; test++) {
        int arraySize = rand() % maxArraySize + 1;
        int* a = new int[arraySize];
        int* b = new int[arraySize];
        for (int i = 0; i < arraySize; i++) {
            a[i] = rand() % maxElementSize;
            b[i] = a[i];
        }
        radixSort(a, arraySize);
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