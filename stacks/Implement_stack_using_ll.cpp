#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node (int data1){
            data= data1;
            next = NULL;
        }
};

class Stack{
    Node* head;

    public :
        Stack(){
            head = NULL;
        }

        void push(int val){
            Node* nn = new Node(val);

            if(!nn){
                cout<<"Stack Overflow";
            }
            nn->next = head;
            head = nn;
        }
        bool empty(){
            return head==NULL;
        }
        void pop(){
            if(empty()){
                cout<<"Stack underflow "<<endl;
            }else{
                Node* temp = head;
                head=head->next;
                delete temp;
            }
        }
        int top(){
            if(!empty()){
                return head->data;
            }else{
                cout<<" Stack is empty "<<endl;
                return INT_MIN;
            }
        }
};

int main(){
    Stack st;
    st.push(50);
    st.push(51);
    st.push(52);
    st.push(53);

    cout<<" Top element is "<<st.top()<<endl;

    st.pop();

    cout<<" Top element is "<<st.top()<<endl;

}