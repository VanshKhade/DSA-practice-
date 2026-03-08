#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int val): data(val),next(NULL) {}
};
void insert(node* &head,int val){
    node* newnode = new node(val);

    if(head==NULL){
        head = newnode;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = newnode;
}

//Approch 1:- counting 
node* sorting(node* head){
    node* curr = head;
    int zero = 0, one = 0, two=0;
    while(curr!=NULL){
        if(curr->data==0) zero++;
        else if(curr->data==1) one++;
        else two++;
        curr = curr->next;
    }
    curr = head;
    while(curr!=NULL){
        if(zero!=0){
            curr->data=0;
            zero--;
        }
        else if(one!=0){
            curr->data = 1;
            one--;
        }
        else{
            curr->data =2;
            two--;
        }
        curr = curr->next;
    }
    return head;
}

//Approach 2:- three linked list
node* sort_012(node* head){
    node* zerohead = new node(-1);
    node* zerotail = zerohead;

    node* onehead = new node(-1);
    node* onetail = onehead;

    node* twohead = new node(-1);
    node* twotail = twohead;
    
    node* curr = head;
    while(curr!= NULL){
        if(curr->data==0){
            zerotail->next = curr;
            zerotail = curr;
        }
        else if(curr->data == 1){
            onetail->next = curr;
            onetail = curr;
        }
        else{
            twotail->next = curr;
            twotail =curr;
        }
        curr = curr->next;
    }
    zerotail->next = (onetail->next !=NULL) ? onetail->next : twotail->next;
    onetail->next = twotail->next;
    twotail->next = NULL;
    return head->next;
}
void printList(node* head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main(){

    node* head = NULL;

    insert(head,1);
    insert(head,0);
    insert(head,2);
    insert(head,1);
    insert(head,0);
    insert(head,2);

    cout<<"Original List:\n";
    printList(head);

    head = sort_012(head);

    cout<<"Sorted List:\n";
    printList(head);
}