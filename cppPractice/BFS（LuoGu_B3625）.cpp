#include<iostream>
#include<queue>
using namespace std;

struct co{
    int n;
    int m;
};

int main(){
    int n,m,total=0;
    cin>>n>>m;
    char a[n][m];
    int mark[n][m];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            mark[i][j]=0;
            cin>>a[i][j];
            if(a[i][j]=='.') total++;
            else mark[i][j]=-1;
        }
    }

    int cnt=0;
    queue<co> q;

    q.push({0,0});

    while(!q.empty() && cnt<=total){
        if(n-1<0 || m-1<0) break;
        if(mark[n-1][m-1]==1){
            cout<<"Yes"<<endl;
            return 0;
        } 
        
        co dad=q.front();

        if(dad.n-1>=0 && mark[dad.n-1][dad.m]==0) q.push({dad.n-1,dad.m}),cnt++,mark[dad.n-1][dad.m]=1;//检查下边并加入
        if(dad.n+1<n && mark[dad.n+1][dad.m]==0) q.push({dad.n+1,dad.m}),cnt++,mark[dad.n+1][dad.m]=1;//检查上边并加入
        if(dad.m-1>=0 && mark[dad.n][dad.m-1]==0) q.push({dad.n,dad.m-1}),cnt++,mark[dad.n][dad.m-1]=1;//检查左边并加入
        if(dad.m+1<m && mark[dad.n][dad.m+1]==0) q.push({dad.n,dad.m+1}),cnt++,mark[dad.n][dad.m+1]=1;//检查右边并加入

        q.pop();

    }
    cout<<"No"<<endl;
    return 0;
}