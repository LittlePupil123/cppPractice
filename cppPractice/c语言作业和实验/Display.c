#include<stdio.h>

int main(){
    for(int i=0;i<4;++i){
        for(int j=3;j>i;--j){
            printf(" ");
        }
        for(int j=0;j<i*2+1;++j){
            printf("*");
        }
        printf("\n");
    }
    for(int i=2;i>=0;--i){
        for(int j=3;j>i;--j){
            printf(" ");
        }
        for(int j=0;j<i*2+1;++j){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}