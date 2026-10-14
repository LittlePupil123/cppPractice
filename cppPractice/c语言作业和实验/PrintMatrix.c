#include<stdio.h>

int main(){
    int res=0;
    int tmp=1;
    for(int i=1;i<=7;++i){
        for(int j=1;j<=i;++j){
            
            tmp*=j;
        }
        res+=tmp;
    }
    printf("res = %d\n",res);

    return 0;
}