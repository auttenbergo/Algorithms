#include<iostream>
#include<algorithm>
#include <time.h>

using namespace std;



void sortASC(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j] < a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}
void sortDESC(int* a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j] > a[j - 1]) {
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    int testSize = 1000;
    int maxArraySize = 1000;
    int maxElementSize = INT_MAX;

    int passed = 0;
    int failed = 0;

    for (int test = 0; test < testSize; test++) {
        int arraySize = rand() % maxArraySize + 1;
        int* testASC = new int[arraySize];
        int* testDESC = new int[arraySize];
        int* expectedASC = new int[arraySize];
        int* expectedDESC = new int[arraySize];
        for (int i = 0; i < arraySize; i++) {
            testASC[i] = rand() % maxElementSize;
            testDESC[i] = testASC[i];
            expectedASC[i] = testASC[i];
            expectedDESC[i] = testASC[i];
        }
        sortASC(testASC, arraySize);
        sortDESC(testDESC, arraySize);
        
        sort(expectedASC, expectedASC + arraySize);
        sort(expectedDESC, expectedDESC + arraySize,greater<int>());

        bool hasPassed = true;

        for (int i = 0; i < arraySize; i++) {
            if (testASC[i] != expectedASC[i]) {
                hasPassed = false;
                break;
            }
        }
        for (int i = 0; i < arraySize; i++) {
            if (testDESC[i] != expectedDESC[i]) {
                hasPassed = false;
                break;
            }
        }

        if (hasPassed)
            passed++;
        else
            failed++;

        delete[]testASC;
        delete[]testDESC;
        delete[]expectedASC;
        delete[]expectedDESC;
    }
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;

    return 0;
}