#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
        int data;
        Node* next;

    public :
        Node(int data1){
            data = data1;
            next = NULL;
        }
        Node (int data1, Node* next1){
            data = data1;
            next = next1;
        }
};

// array into linked list
Node*  make_ll(vector<int>&arr){
    if(arr.size()==0){
        return NULL;
    }
    int n = arr.size();
    Node* head = new Node(arr[0]);
    Node* temp = head;

    for(int i =1;i<n;i++){
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }

    return head;
}

//print linked list 
void printll(Node* head ){
    Node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

// length of linked list
int length_ll(Node* head ){
    Node* temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    
    return count;
}

//search element in Linked List
bool search_ll(Node* head,int val){
    if(head == NULL){
        return false;
    }
    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == val){
            return true;
        }
        temp=temp->next;
    }

    return false;
}

//Insert element at head
Node* insert_at_head_ll(Node*head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* nn = new Node(val);
    nn->next = head;
    head= nn;

    return head;
}

// Insert element at tail
Node* insert_at_tail_ll(Node* head, int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = new Node(val);

    return head;
}

// Insert at mid
Node* insert_At_mid_ll(Node* head, int val, int pos){
    if(pos == 1){
        insert_at_head_ll(head,val);
    }
    
    int count = 0;
    Node* temp = head;

    while(temp != NULL){
        count++;
        if(count-1 == pos){
            Node* temp2 = temp->next;
            temp->next = new Node(val);
            temp->next->next  = temp2;
            return head;
        }
        temp = temp->next;
    }

    return insert_at_tail_ll(head,val);
}


//Delete element at head
Node* delete_at_head_ll(Node*head){
    if(head==NULL || head->next == NULL){
        return NULL;
    }
    
    Node* temp = head;
    head= head->next;

    delete(temp);

    return head;
}

// delete element at tail
Node* delete_at_tail_ll(Node* head){
    if(head==NULL || head->next == NULL){
        return NULL;
    }
    Node* temp = head;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node* temp2 = temp->next;
    temp->next = NULL;

    delete(temp2);
    return head;
}

// delete at mid if pos is given
Node* delete_At_mid_ll(Node* head, int pos){
    
    int count = 0;
    Node* temp = head;

    while(temp != NULL){
        count++;
        if(count-1 == pos){
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete(temp2);
            return head;
        }
        temp = temp->next;
    }

    return head;
}

// delete at mid if val is given
Node* delete_At_mid_val_ll(Node* head, int val){
    Node* temp = head;

    while(temp != NULL){
        if(temp->next->data == val){
            Node* temp2 = temp->next;
            temp->next = temp->next->next;
            delete(temp2);
            return head;
        }
        temp = temp->next;
    }

    return head;
}


// linked list is cyclic or not
bool iscyclic(Node* head){
    if(head == NULL || head->next == NULL){
        return false;
    }

    Node* slow =head;
    Node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main(){
    vector<int>nums={1,2,3,4,5,11,85,36,95};
    Node* head = make_ll(nums);
    printll(head);
    cout<<length_ll(head)<<endl;
    cout<<search_ll(head,36)<<endl;
    cout<<search_ll(head,100)<<endl;
    head = insert_at_head_ll(head,100);
    printll(head);
    return 0;
}