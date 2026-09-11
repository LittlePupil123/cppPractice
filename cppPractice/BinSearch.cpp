#include<iostream>
#include<algorithm>

using namespace std;
long long a[1000000];

int main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    //以上为大数据输入加速

    long long N,M,H=0;
    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    sort(a,a+N);
    long long l=0;
    long long r=a[N-1];

    
    while(r-l>1){
        H=(l+r)/2;
        long long tmp=0;
        for(long long i=0;i<N;i++){
            if(a[i]>H) tmp+=a[i]-H;
            if(tmp>=M) break;
        }
        if(tmp>=M) l=H;
        else r=H;
    }

    cout<<l<<endl;
    return 0;
}