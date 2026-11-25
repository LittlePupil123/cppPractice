#include<stdio.h>

int main(){
    int a[10]={1,2,3,3,5,6,5,7,8,9};
    int tmp=0;
    int l=10;
    for (int i=0;i<10;i++){
        if (a[i]==3){
            l--;
            continue;
        }
        a[tmp]=a[i];
        tmp++;
    }

    for(int i=0;i<l;i++){
        printf("%d ",a[i]);
    }
    printf("\n");

    return 0;
}