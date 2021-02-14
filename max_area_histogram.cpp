#include<iostream>
#include<bits/stdc++.h>
#include<stack>
#include<algorithm>
using namespace std;
#define mod 1000000007

int solve(int a[],int n){
  vector<int>s_left,s_right;
  stack<pair<int,int>>s,t;
  //left smaller
  for(int i=0;i<n;i++){
    if(s.empty()){
        s_left.push_back(-1);
    }
    else if(s.top().first<a[i]){
        s_left.push_back(s.top().second);
    }
    else {
        while(!s.empty()&&s.top().first>=a[i]){
            s.pop();
        }
        if(s.empty())
            s_left.push_back(-1);
        else
            s_left.push_back(s.top().second);
    }
    s.push(make_pair(a[i],i));
  }
//right smaller
  for(int i=n-1;i>=0;i--){
    if(t.empty()){
        s_right.push_back(n);
    }
    else if(t.top().first<a[i]){
        s_right.push_back(t.top().second);
    }
    else {
        while(!t.empty()&&t.top().first>=a[i]){
            t.pop();
        }
        if(t.empty())
            s_right.push_back(n);
        else
            s_right.push_back(t.top().second);
    }
    t.push(make_pair(a[i],i));
  }
  reverse(s_right.begin(),s_right.end());

  int res=0;
  for(int i=0;i<n;i++){
    int l=s_left[i];
    int r=s_right[i];
    int w=r-l-1;
    res=max(res,w*a[i]);
    }

  return res;
}

int main(){
 int n;
 cout<<"Enter no of tower:";
 cin>>n;
 cout<<"Enter height of each tower:";
 int a[n];
 for(int i=0;i<n;i++)
    cin>>a[i];
 cout<<"so the maximum area will be:"<<solve(a,n);

}
