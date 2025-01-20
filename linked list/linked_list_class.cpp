#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
        int data;
        Node* next;

    public:
        Node(int data1){
            data = data1;
            next = NULL;
        }
        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }
};

// array into linked list 
Node* make_ll(vector<int>&arr){
    if(arr.size() == 0){
        return NULL;
    }
    int n= arr.size();

    Node* head = new Node(arr[0]);//1->NULL
    Node* temp = head;

    for(int i =1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp= temp->next;
    }
    return head;
}

//print linked list 
void print_ll(Node* head){
    Node* temp = head;

    while(temp!= NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;;
}
//length of ll
int length_ll(Node* head){
    Node* temp = head;
    int count  = 0;
    while(temp!= NULL){
        count++;
        // cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    // cout<<"NULL"<<endl;;
    return count;
}

//search element in Linked List
bool search_ll(Node* head, int val){
    if(head==NULL){
        return false;
    }
    Node* temp = head;
    while(temp!= NULL){
        if(temp->data == val){
            return true;
        }
        temp=temp->next;
    }

    return false;
}
//insert element at head
Node* insert_At_head(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }

    Node* nn = new Node(val);
    nn->next = head;
    head=nn;

    return head;
}
1->2->3->NULL
//delete element at head
Node* delete_At_head(Node* head){
    if(head==NULL){
        return NULL;
    }

    // // Node* nn = new Node(val);
    // nn->next = head;
    // head=nn;

    Node* temp2 = head;
    head= head->next;
    delete(temp2);
    return head;
}

// Insert element at tail 
Node* insert_At_tail(Node* head ,int val){
    if(head == NULL){
        return new Node(val);
    }

    Node* temp = head;

    while(temp->next != NULL){
        temp=temp->next;
    }

    temp->next = new Node(val);

    return head;
}

// Delete element at tail 
Node* delete_at_tail(Node* head ){
    if(head == NULL){
        return NULL;
    }
    // 1->45->100->22->25->1->36->85->46->NULL
    Node* temp = head;

    while(temp->next->next != NULL){
        temp=temp->next;
    }

    Node* temp2 = temp->next;
    temp->next =NULL;

    delete(temp2);

    return head;
}

// Insert element at pos
Node* insert_At_mid(Node* head, int val, int pos){
    if(pos == 1){
        return insert_At_head(head,val);
    }

    int count  = 0;
    Node* temp = head;

    while(temp!=NULL){
        count++;
        if(count-1 == pos){
            Node* temp2 = temp->next;
            temp->next = new Node(val);
            temp->next->next  = temp2;
            return head;
        }
        temp =temp->next;
    }

    return insert_At_tail(head,val);
}

// delete element at pos
Node* delete_At_mid(Node* head,  int pos){
    if(pos == 1){
        return delete_At_head(head);
    }

    int count  = 0;
    Node* temp = head;
    // 1->45->100->22->25->1->36->85->46->NULL
    while(temp!=NULL){
        count++;
        if(count-1 == pos){
            Node* temp2 = temp->next;
            // temp->next = new Node(val);
            temp->next  = temp2->next;
            delete(temp2);
            return head;
        }
        temp =temp->next;
    }

    return head;
}
int main(){
    vector<int>arr = { 45, 100,25,36,85,46};
    // 1->45->100->22->25->1->36->85->46->NULL
    Node* head = make_ll(arr);
    print_ll(head);
    cout<<search_ll(head,85)<<endl;
    cout<<search_ll(head,-456)<<endl;
    return 0;
}