#include<iostream>
using namespace std;
struct node{
    int data;
    node* prev;
    node* next;
    node(int val) : data(val) , prev(NULL) , next(NULL) {}
};
void insertatHead(node*&head,node*&tail,int val){
    node* temp = new node(val);
    if(head==NULL){
        head=tail=temp;
        return;
    }
    temp->next = head;
    head->prev = temp;
    head = temp;
    
}
void insertatTail(node*&head,node*&tail,int val){
    node* temp = new node(val);
    if(head == NULL){
        head = tail = temp;
        return;
    }
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertatPosition(node*&head,node*&tail,int val,int pos){
    if(head==NULL) return;
    if(pos==1){
        insertatHead(head,tail,val);
        return;
    }
    node* temp = head;
    int cnt = 1;
    while(cnt<pos-1 && temp->next!=NULL){
        temp = temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertatTail(head,tail,val);
        return;
    }
    node* newnode = new node(val);
    node * nextNode = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    
    newnode->next = nextNode;
    nextNode->prev = newnode;
}
bool deleteAtPosition(node*& head, node*& tail, int pos){
    if(head == NULL || pos <= 0)
        return false;
    if(pos == 1) {
        node* temp = head;
        head = head->next;
        if(head != NULL)
            head->prev = NULL;
        else
            tail = NULL; 
        delete temp;
        return true;
    }
    node* curr = head;
    int count = 1;
    while(count < pos && curr != NULL) {
        curr = curr->next;
        count++;
    }
    if(curr == NULL)
        return false;
    if(curr == tail) {
        tail = curr->prev;
        tail->next = NULL;
        delete curr;
        return true;
    }
    node* prevNode = curr->prev;
    node* nextNode = curr->next;
    prevNode->next = nextNode;
    nextNode->prev = prevNode;
    delete curr;
    return true;
}
node* reversing(node* head){
  if(head==NULL || head ->next == NULL){
    return;
  }
  node* curr = head;
  node* temp = NULL;
  while(curr!=NULL){
    temp = curr->prev;
    curr->prev = curr->next;
    curr->next = temp;
    curr = curr->prev;
}
if(head!=NULL){
    head = temp->prev;
}
return head;
}   
    
void printList(node* head){
    if(head==NULL) return;
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}
int length(node*&head){
    int lent = 0;
    while(head!=NULL){
        lent++;
        head = head->next;
    }
    return lent;
}

int main(){
    node* head =NULL;
    node* tail = NULL;
    insertatHead(head,tail,10);
    insertatTail(head,tail,20);
    insertatPosition(head,tail,30,2);
    deleteAtPosition(head,tail,2);
    printList(head);
    deleteAtPosition(head,tail,2);
    printList(head);

}