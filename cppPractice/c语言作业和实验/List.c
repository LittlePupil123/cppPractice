#include<stdio.h>

struct List
{
    int val;
    struct List* next;
};


int main(){
    struct List a1;
    struct List a2;
    struct List a3;
    struct List a4;
    struct List a5;
    
    a1.next=&a2;
    a2.next=&a3;
    a3.next=&a4;
    a4.next=&a5;
    a5.next=NULL;

    
    return 0;
}