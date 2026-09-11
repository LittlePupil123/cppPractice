#include<iostream>
using namespace std;
const int num=3;
int route[num];

void dfs(int depth,int left_num,int lastNum){
    if(depth==num){
        if(left_num==0){
            for(int i=0;i<num;i++) cout<<route[num-i-1]<<" ";
            cout<<endl;
            return;
        }
        return;
    }

    for(int i=1;i<=left_num && i<=lastNum;i++){
        route[depth]=i;
        dfs(depth+1,left_num-route[depth],route[depth]);
    }
}


int main (){
    int N;
    cin>>N;
    
    dfs(0,N,N);

    return 0;
}