#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void insert(vector<int>& h,int tmp,int n){
    h.push_back(tmp);
    int i=n;
    while(i>1){
        if(h[i]>=h[i/2]) break;
        swap(h[i],h[i/2]);
        i=i/2; 
    }
}

int pop(vector<int>& h,int& N){
    int res=h[1];
    swap(h[1],h[N]);
    h.pop_back();
    N--;
    //向下调整堆顶
    int i=1;
    while(i*2<=N){//保证有下一层
        if(i*2+1<=N){//判断是否存在右子树以防止出界
            if(h[i]<=min(h[i*2],h[i*2+1])) break;
            if(h[i*2]>h[i*2+1]){
                swap(h[i],h[i*2+1]);
                i=i*2+1;
            }
            else{
                swap(h[i],h[i*2]);
                i=i*2;
            }
        }
        else{
            if(h[i]<=h[i*2]) break;
            swap(h[i*2],h[i]);
            i=i*2;
        }
    }

    return res;
}

int main(){
    vector<int> h(1,0);
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        int tmp;
        cin>>tmp;
        insert(h,tmp,i);
    }
    // for(int i=1;i<=N;i++){
    //     cout<<h[i]<<" ";
    // }
    int len=N;
    for(int i=1;i<=len;i++){
        int tmp=pop(h,N);
        cout<<tmp<<" ";
    }
    return 0;
}

//我创建的是一个小顶堆+选择排序。如果需要对原数组进行排序。那么可以变成一个大顶堆，然后每次把堆顶放到数组末尾，最后形成的排序即为升序