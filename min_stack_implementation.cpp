#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


int main(){
 //we are using supporting stack to implement it
 stack<int>s,aux;
 char ch='Y';
 do{
 cout<<"Enter your choice:\n";
 cout<<"1. PUSH ELEMENT\n";
 cout<<"2. POP ELEMENT\n";
 cout<<"3. FIND MINIMUM ELEMENT\n";
 int c;
 cin>>c;
 switch(c){
case 1:
    int val;
    cout<<"Enter the value to push:";
    cin>>val;
    s.push(val);
    if(aux.empty())
        aux.push(val);
    else{
        if(aux.top()>=val)
        aux.push(val);
    }
    stack<int>temp;
    while(!s.empty()){
      temp.push(s.top());
      s.pop();
     }
     cout<<"Stack--->";
     while(!temp.empty()){
        cout<<temp.top()<<" ";
        s.push(temp.top());
        temp.pop();
      }
      break;

case 2:
    if(s.empty())
      cout<<"Empty stack cant not perform pop.";
    else{
      if(aux.top()==s.top())
      aux.pop();
      s.pop();
      if(s.empty())
        cout<<"stack become empty.";
      else{
        stack<int>temp;
        while(!s.empty()){
          temp.push(s.top());
          s.pop();
        }
       cout<<"Stack--->";
       while(!temp.empty()){
         cout<<temp.top()<<" ";
         s.push(temp.top());
         temp.pop();
       }
      }
    }
    break;

case 3:
    cout<<"minimum element of stack:"<<aux.top()<<"\n";
    break;
default :
    cout<<"Enter right choice.";
    break;

 }
 cout<<"\nDo you want to continue:Y/N--";
 cin>>ch;
 }while(ch=='Y');

}

