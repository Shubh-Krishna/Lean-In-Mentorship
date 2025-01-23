#include<bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* next;
    Node(int new_data)
    {
        data = new_data;
        next = NULL;
    }
};

class Queue{
    Node *front ,*tail;
public :
    Queue(){
        front = NULL;
        tail = NULL;
    }
    bool empty(){
        if(front==NULL){
            return true;
        }
        return false;
    }

    void enqueue(int val){
        Node* nn = new Node(val);

        if(empty()){
            front =nn;
            tail = nn;
        }
        tail->next = nn;
        tail = nn;
    }

    void dequeue(){
        if(empty()){
            cout<<"Queue underflow "<<endl;
            return;
        }

        Node* temp = front;
        front =front->next;

        if(front == NULL){
            tail = NULL;
        }

        delete temp;
    }

    int Front(){
        if(empty()){
            cout<<"Queue is empty "<<endl;
            return INT_MIN;
        }

        return front->data;
    }
};

int main(){
    Queue q;
    q.enqueue(123);
    q.enqueue(156);
    q.enqueue(132);
    q.enqueue(112);

    cout<<q.Front()<<endl;

    while(!q.empty()){
        cout<<q.Front()<<" ";
        q.dequeue();
    }
    cout<<endl;

    return 0;
}