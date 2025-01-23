#include<bits/stdc++.h>
using namespace std;
void print_stk (stack<int> s){
    while(!s.empty()){
        cout<<s.top()<< endl;
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> container;
    
    container.push(21);
    container.push(22);

    print_stk(container);

    return 0;
}