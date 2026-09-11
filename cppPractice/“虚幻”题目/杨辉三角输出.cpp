#include<iostream>
#include<vector>
using namespace std;

int ROW;

vector<vector<int> > generate(int row){
    vector<vector<int> > res;
    res.push_back({1});
    if(row==1) return res;
    res.push_back({1,1});
    if(row==2) return res;
    for(int i=2;i<row;i++){
        res.push_back(vector<int> (i+1,1));
        for(int j=1;j<((i+2)/2);j++){
            res[i][j]=res[i-1][j-1]+res[i-1][j];
            res[i][i-j]=res[i][j];
        }
    }
    return res; 

}


int main(){
    
    cin>>ROW;
    vector<vector<int> > res;
    res=generate(ROW);
    for(int i=0;i<ROW;i++){
        int l=res[i].size();
        for(int j=0;j<l;j++) cout<<res[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}