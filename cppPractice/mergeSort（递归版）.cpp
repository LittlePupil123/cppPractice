#include<iostream>
#include<vector>

using namespace std;

void debug(vector<int>& tmp,int *a,int l,int r,int mid){
    cout<<"-----------------"<<endl;
    cout<<"l,r,mid:"<<l<<" "<<r<<" "<<mid<<endl;
    int len=size(tmp);
    cout<<"size tmp:"<<len<<endl;
    cout<<"a:";
    for(int i=l;i<=r;i++) cout<<a[i]<<" ";
    cout<<endl;

    cout<<"tmp:";
    for(int i=0;i<len;i++) cout<<tmp[i]<<" ";
    cout<<endl;
    cout<<"-------------------"<<endl;
}

void merge(vector<int>& tmp,int *a,int l1,int r1,int l2,int r2){
    int i=l1;
    int j=l2;
    while(i<=r1 && j<=r2){

        // cout<<"(before)i,j:"<<i<<" "<<j<<endl;
        // debug(tmp,a,l1,r2,r1);

        if(a[i]<=a[j]){//必须是<=而不是<，从而保证原数组左边的（升序）先填入tmp，进而保证稳定性
            tmp.push_back(a[i]);
            i++;
        }
        else{
            tmp.push_back(a[j]);
            j++;
        }

        // cout<<"(after)i,j:"<<i<<" "<<j<<endl;
        // debug(tmp,a,l1,r2,r1);
    }
    //对于填完一个数组后，将另一个数组剩下的元素填充到tmp尾部
    for(;i<=r1;i++) tmp.push_back(a[i]);
    for(;j<=r2;j++) tmp.push_back(a[j]);

    // cout<<"(res)i,j:"<<i<<" "<<j<<endl;
    // debug(tmp,a,l1,r2,r1);
}//对[l1,r1]，[l2,r2]闭区间的数组a进行合并;即l，r为索引，而不是长度

void mergeSort(int l,int r,int *a){//对[l,r]的闭区间做操作
    if(r-l<1) return;//当分割成了长度为1的区间，则该区间本身就有序了，只需去合并，故不需分割，直接终止返回

    //分割长度大于1的区间致使去形成有序数列（长度为1）
    int mid=(l+r)/2;
    mergeSort(l,mid,a);//分割出左半边；
    mergeSort(mid+1,r,a);

    //对形成的两有序区间做合并
    vector<int> tmp;
    // cout<<"合并前"<<endl;
    // debug(tmp,a,l,r,mid);
    
    merge(tmp,a,l,mid,mid+1,r);
    
    // cout<<"合并后"<<endl;
    // debug(tmp,a,l,r,mid);
    
    int cnt=0;
    for(int i=l;i<=r;i++){
        a[i]=tmp[cnt];
        cnt++;
    }

    // cout<<"返回到a后"<<endl;
    // debug(tmp,a,l,r,mid);
}


int main(){
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }

    mergeSort(0,N-1,a);

    for(int i=0;i<N;i++){
        cout<<a[i]<<" ";
    }
}