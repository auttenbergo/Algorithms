#include<iostream>

using namespace std;

const long n = 1000000;

void fillArrayWithZeros(int a[]){
    for(long i=0;i<n;i++){
        a[i] = 0;
    }
}

int main(){
    int arr[n];
    fillArrayWithZeros(arr);
    for(long i=2; i<n; i++){
        if(arr[i] == 1)
            continue;
        for(long j = i * i; j < n ; j += i){
            arr[j] = 1;
        }
    }
    int counter = 0;
    for(long i=2; i<n; i++){
        if(arr[i] == 0){
            cout<<i<<" ";
            counter++;
        }
        if(counter == 10){
            counter = 0;
            cout<<endl;
        }
    }
       
    return 0;
}