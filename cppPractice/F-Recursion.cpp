#include<iostream>
using namespace std;

int Recursion(int n){
    if(n==1) return 1;
    if(n==0) return 0;
    return Recursion(n-1)+Recursion(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<Recursion(n)<<endl;
}