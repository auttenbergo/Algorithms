#include<iostream>
#include<algorithm>
#include <time.h>

using namespace std;


void sortASC(int* a, int n) {
    for (int i = 0; i < n; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        int tmp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = tmp;
    }
}

void sortDESC(int* a, int n) {
    for (int i = 0; i < n; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[maxIndex]) {
                maxIndex = j;
            }
        }
        int tmp = a[i];
        a[i] = a[maxIndex];
        a[maxIndex] = tmp;
    }
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

        int* testASC = new int[arraySize];
        int* expectedASC = new int[arraySize];

        int* testDESC = new int[arraySize];
        int* expectedDESC = new int[arraySize];

        for (int i = 0; i < arraySize; i++) {
            int num = rand() % maxIntegerValue;
            testASC[i] = num;
            expectedASC[i] = num;
            testDESC[i] = num;
            expectedDESC[i] = num;
        }

        sortASC(testASC,arraySize);
        sort(expectedASC, expectedASC + arraySize);

        sortDESC(testDESC, arraySize);
        sort(expectedDESC, expectedDESC + arraySize, greater<int>());


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
        delete[]expectedASC;

        delete[]testDESC;
        delete[]expectedDESC;

    }
    cout << "Passed: " << passed << endl;
    cout << "Failed: " << failed << endl;

    return 0;
}