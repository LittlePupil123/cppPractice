#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void PreSum(vector<vector<int> >& a,int n,int m){//将数组变为前缀和数组,二维数组，所以采用容斥原理进行处理
    // for(int i=1;i<n;i++){
    //     a[i][0]+=a[i-1][0];
    // }
    // for(int i=1;i<m;i++){
    //     a[0][i]+=a[0][i-1];
    // }
    // for(int i=1;i<n;i++){
    //     for(int j=1;j<m;j++){
    //         a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    //     }
    // }

    //---------逐维处理法（适合高维度(2维以上均可)）----------------
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j]+=a[i-1][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            a[i][j]+=a[i][j-1];
        }
    }
}

int checkSum(vector<vector<int> >& a,int n1,int m1,int n2,int m2){ //返回数组（n1,m1）到(n2,m2)的矩阵的和
    if(m1>0 && n1>0) return (a[n2][m2]-a[n2][m1-1]-a[n1-1][m2]+a[n1-1][m1-1]);//正方形上边，左边均不在数组边界
    if(m1>0) return (a[n2][m2]-a[n2][m1-1]);//正方形上边在边界
    if(n1>0) return (a[n2][m2]-a[n1-1][m2]);//正方形左边在边界
    return a[n2][m2];//正方形起始点为数组顶点
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int> > a(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    PreSum(a,n,m);
    
    // cout<<endl;
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         cout<<a[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    int l=min(n,m);//当前尝试的边长,初始最大边长取min（n，m），也就是最大可能的边长，然后逐渐枚举，失败就减小边长重试，成功就输出
    while(l>1){
        for(int i=0;i<n;i++){
            if((i+l-1)>=n) break;
            for(int j=0;j<m;j++){
               if((j+l-1)>=m) break;
               int tmp=checkSum(a,i,j,i+l-1,j+l-1);
               if(tmp==(l*l)){
                    cout<<l;
                    return 0;
               } 
            }
        }
        l--;
    }
    cout<<1;
    return 0;    
}