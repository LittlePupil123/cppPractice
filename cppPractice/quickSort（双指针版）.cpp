#include<iostream>
#include<algorithm>
using namespace std;

void quickSort(int l,int r,int *a){//对[l,r)区间的数组快排
    if(l>=r) return;

    //规定key=a[l]
    int key=a[l];
    int i=l;
    swap(a[l],a[r-1]);//将key移到区间末尾，方便j遍历

    for(int j=l;j<r-1;j++){//原地分区(j不遍历到区间最后一个（key值）)。i代表小于key的分组的临界点；当j遍历完成后i代表key所在的索引
        if(a[j]<key){
            swap(a[i],a[j]);
            i++;
        }
    }
    swap(a[i],a[r-1]);

    quickSort(l,i,a);//对左区间继续快排
    quickSort(i+1,r,a);//对右区间继续快排

}


int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }

    quickSort(0,N,a);
    for(int i=0;i<N;i++) cout<<a[i]<<" ";

}