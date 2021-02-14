#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define mod 1000000007
void nearest_smaller_left(int arr[],int n){
stack<int>s;
vector<int>v;
for(int i=0;i<n;i++){
    if(s.empty()){
        v.push_back(-1);
    }
    else if(s.top()<arr[i]){
        v.push_back(s.top());
    }
    else{
        while(!s.empty()&&s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty())
            v.push_back(-1);
        else
            v.push_back(s.top());
    }
    s.push(arr[i]);
}
    for(auto x:v){
        cout<<x<<" ";
    }
}

void nearest_smaller_right(int arr[],int n){
stack<int>s;
vector<int>v;
for(int i=n-1;i>=0;i--){
    if(s.empty()){
        v.push_back(-1);
    }
    else if(s.top()<arr[i]){
        v.push_back(s.top());
    }
    else{
        while(!s.empty()&&s.top()>=arr[i]){
            s.pop();
        }
        if(s.empty())
            v.push_back(-1);
        else
            v.push_back(s.top());
    }
    s.push(arr[i]);
   }
   reverse(v.begin(),v.end());
    for(auto x:v){
        cout<<x<<" ";
    }
}

void nearest_greater_left(int arr[],int n){
stack<int>s;
vector<int>v;
for(int i=0;i<n;i++){
    if(s.empty()){
        v.push_back(-1);
    }
    else if(s.top()>arr[i]){
        v.push_back(s.top());
    }
    else{
        while(!s.empty()&&s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty())
            v.push_back(-1);
        else
            v.push_back(s.top());
    }
    s.push(arr[i]);
}
    for(auto x:v){
        cout<<x<<" ";
    }
}

void nearest_greater_right(int arr[],int n){
stack<int>s;
vector<int>v;
for(int i=n-1;i>=0;i--){
    if(s.empty()){
        v.push_back(-1);
    }
    else if(s.top()>arr[i]){
        v.push_back(s.top());
    }
    else{
        while(!s.empty()&&s.top()<=arr[i]){
            s.pop();
        }
        if(s.empty())
            v.push_back(-1);
        else
            v.push_back(s.top());
    }
    s.push(arr[i]);
   }
   reverse(v.begin(),v.end());
    for(auto x:v){
        cout<<setw(3)<<x<<" ";
    }
}

int main(){
 int n;
 cout<<"Enter the no of element in the array: ";
 cin>>n;
 int a[n];
 cout<<"enter all the element: ";
 for(int i=0;i<n;i++){
    cin>>a[i];
 }
 int c;
 char ans='Y';
 do{
 cout<<"\nEnter your choice:\n";
 cout<<"1. nearest greater element to right\n";
 cout<<"2. nearest greater element to left\n";
 cout<<"3. nearest smaller element to right\n";
 cout<<"4. nearest smaller element to left\n";
 cin>>c;
 switch(c){
   case 1:
       nearest_greater_right(a,n);
       break;
   case 2:
       nearest_greater_left(a,n);
       break;
   case 3:
       nearest_smaller_right(a,n);
       break;
   case 4:
       nearest_smaller_left(a,n);
       break;
   default:
    cout<<"Enter right choice.";
    break;
 }
 cout<<"\nwant to continue --Y/N:";
 cin>>ans;
 }while(ans=='Y');
}
