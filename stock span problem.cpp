#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 1000000007
void solve(int a[],int n){
 stack<pair<int,int>>s;
 vector<int>v;

 for(int i=0;i<n;i++){
    if(s.empty()){
        v.push_back(-1);
    }
    else if(s.top().first>a[i]){
        v.push_back(s.top().second);
    }
    else{
        while(!s.empty()&&s.top().first<=a[i]){
            s.pop();
        }
        if(s.empty())
            v.push_back(-1);
        else
            v.push_back(s.top().second);
    }
    s.push(make_pair(a[i],i));
 }

 for(int i=0;i<n;i++){
   v[i]=i-v[i];
 }
 for(auto x:v){
    cout<<x<<" ";
 }

}

int main(){
 int n;
 cout<<"Enter the no of element: ";
 cin>>n;
 cout<<"Enter the element:";
 //we need to find the no of contiguous element that are smaller or equal than the current element including self .
 int a[n];
 for(int i=0;i<n;i++)
    cin>>a[i];
 solve(a,n);
}
