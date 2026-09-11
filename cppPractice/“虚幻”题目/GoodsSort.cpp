#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

struct GoodsInfo{
    int num;
    std::string name;
};

struct GoodList
{
    GoodList* next;//储存指向下一个商品节点的指针 
    GoodsInfo data;//储存商品信息 
};

extern int CurrentCnt; //全局变量，表示现在已有的商品数量 
bool insert_item(GoodList *L, GoodsInfo goodsInfo, int choice)
{
    //TODO
    if(choice==0){
        GoodList *i=L;
        while(i->next!=nullptr) i=i->next;
        i->data=goodsInfo;
        return true;
    }
    else if(choice==1){
        GoodList *i=L->next;
        GoodList tmp;
        tmp.data=goodsInfo;
        tmp.next=i;
        L->next=&tmp;
        return true;
    }
    else{
        GoodList j;
        j.data=goodsInfo;
        GoodList *tmp=L;
        for(int i=1;i<choice;i++) tmp=tmp->next;
        j.next=tmp->next;    
        tmp->next=&j;
        return true;
    }

    //END
    return false;
}

int main(){

    return 0;
}