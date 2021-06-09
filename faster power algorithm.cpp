#include<iostream>

using namespace std;

int pow(int x,int n){
    if(n == 0)
        return 1;
        
    if(n % 2 == 0){
        int result = pow(x,n/2);
        return result * result;
    }
    
    int result = pow(x,n/2);
    return result * result * x;
}

int main() {
    int n; int x;
    cin >> n; cin >> x;
    
    int res = pow(n,x);
    cout<<res<<endl;
    return 0;

}