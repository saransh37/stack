#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int solve(int a[][100],int n,int ind){
  vector<int>s_left,s_right;
  stack<pair<int,int>>s,t;
  //left smaller
  for(int i=0;i<n;i++){
    if(s.empty()){
        s_left.push_back(-1);
    }
    else if(s.top().first<a[ind][i]){
        s_left.push_back(s.top().second);
    }
    else {
        while(!s.empty()&&s.top().first>=a[ind][i]){
            s.pop();
        }
        if(s.empty())
            s_left.push_back(-1);
        else
            s_left.push_back(s.top().second);
    }
    s.push(make_pair(a[ind][i],i));
  }
//right smaller
  for(int i=n-1;i>=0;i--){
    if(t.empty()){
        s_right.push_back(n);
    }
    else if(t.top().first<a[ind][i]){
        s_right.push_back(t.top().second);
    }
    else {
        while(!t.empty()&&t.top().first>=a[ind][i]){
            t.pop();
        }
        if(t.empty())
            s_right.push_back(n);
        else
            s_right.push_back(t.top().second);
    }
    t.push(make_pair(a[ind][i],i));
  }
  reverse(s_right.begin(),s_right.end());

  int res=0;
  for(int i=0;i<n;i++){
    int l=s_left[i];
    int r=s_right[i];
    int w=r-l-1;
    res=max(res,w*a[ind][i]);
    }

  return res;
}

int main(){
 int n;
 cout<<"enter the dimension of matrix:";
 cin>>n;
 int a[100][100];
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
 }
 //converting matrix into histogram
 for(int i=1;i<n;i++){
    for(int j=0;j<n;j++){
        if(a[i][j]==1)
            a[i][j]=a[i-1][j]+1;
    }
 }
 cout<<"Histogram matrix"<<"\n";
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<a[i][j]<<" ";
    }
    cout<<"\n";
 }
 int res=0;
 for(int i=0;i<n;i++){
    res=max(res,solve(a,n,i));
 }
 cout<<"maximum area of triangle"<<res<<"\n";

}
