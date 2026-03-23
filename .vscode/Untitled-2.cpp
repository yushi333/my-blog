#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    int m;
    cin>>m;
    map<int,int>a;
    queue<int>b;
    for(int j=1;j<=m;j++){
      for(int k=1;k<=m;k++){
       int q;
       cin>>q;
       if(a[q]==0){
        b.push(q);
        a[q]++;
       }else{
        a[q]++;
       }
 
      }
    }
    int ans=0;
    while(!b.empty()){
      if(a[b.front()]>(m-1)*m+1){
       cout<<"no"<<endl;
       ans=1;
      }
      b.pop();
    }
   if(ans!=1)cout<<"yes"<<endl;


    }
    return 0;
}