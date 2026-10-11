#include<stdio.h>

int main(){
    int res=0;
    for(int i=2;i<=100;i+=2){
        res+=i;
    }
    printf("res is %d\n",res);

    return 0;
}