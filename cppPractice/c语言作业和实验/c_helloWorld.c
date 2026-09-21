#include<stdio.h>

int main(){
    printf("hello,world!\n");
    int a,b;
    float c=4.223,d=9.0;
    printf("输入：");
    scanf("%d,%d",&a,&b);
    printf("%d %8d\n%.4f,%.2f",a,b,c,d); //%.3f表示保留3位小数的格式打印，%3d表示额外占三格，用空格填充额外占用格
    
    return 0;
}
//转义序列常用：\n表示换行    \t表示水平制表（一般输出4个空格）   \a表示警报符    \b表示回退符