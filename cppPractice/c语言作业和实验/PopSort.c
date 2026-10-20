#include<stdio.h>

void Sort(int *a,int len){
    for(int i=1;i<len;i++){
        int tmp=i;
        while(a[tmp]<a[tmp-1] && tmp-1 >= 0){
                //交换
                a[tmp]=a[tmp]+a[tmp-1];
                a[tmp-1]=a[tmp]-a[tmp-1];
                a[tmp]=a[tmp]-a[tmp-1];
                tmp--;
            
        }
    }
}

void test(){
    int a[10]={3,1,6,7,9,0,1,4,8,10};
    Sort(a,10);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int main(){
    test();
}