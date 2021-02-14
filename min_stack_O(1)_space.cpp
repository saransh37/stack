#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
stack<int>s;
int res=-1;;
char ch='Y';
 do{
 cout<<"Enter your choice:\n";
 cout<<"1. PUSH ELEMENT\n";
 cout<<"2. POP ELEMENT\n";
 cout<<"3. FIND MINIMUM ELEMENT\n";
 cout<<"4.  TOP ELEMENT\n";
 int c;
 cin>>c;
 switch(c){
case 1:
    int val;
    cout<<"Enter the value to push:";
    cin>>val;
    if(s.empty()){
        s.push(val);
        res=val;
    }
    if(val>res)
    s.push(val);
    else{
        s.push(2*val-res);
        res=val;
    }
      break;

case 2:
    if(s.empty())
      cout<<"Empty stack cant not perform pop.";
    else{
      if(s.top()<res){
        res=2*res-s.top();
        s.pop();
      }
      else{
        s.pop();
      }
    }
    break;

case 3:
    cout<<"minimum element of stack:"<<res<<"\n";
    break;
case 4:
    if(s.top()>res)
    cout<<"TOP element of stack:"<<s.top()<<"\n";
    else
     cout<<"TOP element of stack:"<<res<<"\n";
    break;
default :
    cout<<"Enter right choice.";
    break;

 }
 cout<<"\nDo you want to continue:Y/N--";
 cin>>ch;
 }while(ch=='Y');

}
