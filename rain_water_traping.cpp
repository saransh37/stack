#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
int n;
cout<<"Enter no of tower:";
cin>>n;
cout<<"Enter height of all towers:";
int a[n];
for(int i=0;i<n;i++)
  cin>>a[i];
int res=0;

//depend upon the right max and left maximum value
int left[n],right[n];
int val=-1;
for(int i=0;i<n;i++){
    val=max(val,a[i]);
    left[i]=val;
}
val=-1;
for(int i=n-1;i>=0;i--){
    val=max(val,a[i]);
    right[i]=val;
}

for(int i=0;i<n;i++){
    int v=min(left[i],right[i]);
    res+=v-a[i];
}
cout<<"maximum water trapped:"<<res<<"\n";

}
