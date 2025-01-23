#include <bits/stdc++.h>
using namespace std;

#define MAX 1000 

class Stack {
    int top ;

    public : 
        int a[MAX];

        Stack(){
            top = -1;
        }
        bool push(int x);
        int pop();
        int peek();
        bool Empty();
};

bool Stack ::push(int x){
    if(top >= (MAX-1)){
        cout<<"Stack Overflow";
        return false;
    }else{
        a[++top] = x;
        cout<<x<<" : element added in stack"<<endl;
        return true;
    }
}

int Stack :: pop(){
    if(top < 0){
        cout<<"Stack is Empty ";
        return 0;
    }else{
        int x = a[top--];
        return x;
    }
}

int Stack :: peek(){
    if(top<0){
        cout<<"Stack is Empty ";
        return 0;
    }else{
        int x = a[top];
        return x;
    }
}

bool Stack :: Empty(){
    return (top< 0);
}

int main(){
    class Stack s;
    s.push(10);
    s.push(20);
    cout<<s.pop()<< " is popped"<<endl;
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    while(!s.Empty()){
        cout<<s.peek()<<endl;
        s.pop();
    }

    return 0;
}