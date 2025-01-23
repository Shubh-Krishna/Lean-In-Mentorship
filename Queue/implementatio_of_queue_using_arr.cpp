#include<bits/stdc++.h>
using namespace std;

class Queue{
    public:
        vector<int>arr;
        int size;
        int capacity;
        int front;

        Queue(int qsize){
            size = 0;
            front = 0;
            capacity =qsize;
            arr.resize(qsize);
        }

        void enqueue(int x){
            if(size == capacity){
                return ;
            }

            arr[size]=x;
            size++;
        }

        void dequeue(){
            if(size == 0){
                cout<<"no element is there "<<endl;
                return;
            }
            front++;
        }

        int Front(){
            if(size == 0){
                cout<<"Queue is underflow";
                return -1;
            }
            return arr[front];
        }

        void display(){
            for(int i = front;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        bool empty(){
            if(front == size){
                return true;
            }
            return false;
        }
};

int main(){
    Queue* q = new Queue(10);// 14 21
    q->enqueue(1);
    q->enqueue(14);
    q->enqueue(21);
    cout<<q->Front()<<endl;
    q->dequeue();
    q->display();
    q->enqueue(100);
    q->display();

    return 0;
}