#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
        int data;
        Node* next;
        Node* prev;

    public :
        Node(int data1){
            data = data1;
            next = NULL;
            prev = NULL;
        }
        Node (int data1, Node* next1){
            data = data1;
            next = next1;
            prev = NULL;
        }
        Node(int data1, Node* next1, Node* prev1){
            data = data1;
            next = next1;
            prev= prev1;
        }
};

int main(){

    return 0;
}