#include<stdio.h>
#include<stdbool.h>

bool Judge(int num){
    for(int i=2;i<num;i++){
        if(num%i==0) return false;
    }
    return true;
}

int main(){
    int num;
    printf("input the num >>>");
    scanf("%d",&num);
    if(Judge(num)) printf("yes\n");
    else printf("no\n");
    return 0;
}