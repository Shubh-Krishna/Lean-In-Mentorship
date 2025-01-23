#include<bits/stdc++.h>
using namespace std;

void que_show(queue<int>&k){
    queue<int>g = k;
    while(!g.empty()){
        cout<<g.front()<<" ";
        g.pop();
    }
    cout<<endl;
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(11);
    q.push(12);

    q.push(100);
    q.push(110);
    q.push(102);

    que_show(q);

    cout<<q.size()<<endl;
    cout<<"front elemnt is "<<q.front()<<endl;
    cout<<" back element is "<<q.back()<<endl;
    q.pop();
    cout<<"front element after popping is "<<q.front()<<endl;
    cout<<" back element after popping is "<<q.back()<<endl;
    q.pop();

    que_show(q);

    return 0;
}