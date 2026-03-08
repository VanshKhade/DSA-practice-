#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int val) : data(val) , next(NULL) {}
};
void insert(node*&tail,int element,int val){
    if (tail==NULL){
        node* newNode = new node(val);
        tail = newNode;
        newNode->next = newNode;
        return;
    }
    node* curr = tail;
    do{
        if(curr->data == element){
            node* newNode = new node(val);
            newNode->next = curr->next;
            curr->next = newNode;
            if(curr==tail)
                tail = newNode;
            return;
        }
        curr = curr->next;
    }while(curr != tail);
}
void printList(node* tail){
    if(tail==NULL) return;
    node* temp = tail->next;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail->next);
    cout<<endl;

}
bool deletevalue(node*&tail,int key){
    if(tail == NULL) return false;
    node* prev = tail;
    node* curr = tail->next;
    do{
        if(curr->data==key){
            prev->next = curr->next;
            if(curr == prev){
                tail = NULL;
            }
            else if(curr == tail){
                tail = prev;
            }
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }while(curr != tail->next);
    return false;
}
node* reversing(node* head){
    if(head==NULL || head->next==NULL){
        return;
    }
    node* prev = NULL;
    node* curr = head;
    node* Next ;
    do{
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }while(curr!=head);
    head->next = prev;
    head = prev;
    return head;
}
int main(){
    node * tail = NULL;
    insert(tail,0,2);
    insert(tail,2,4);
    insert(tail,2,3);
    printList(tail);
    deletevalue(tail,2);
    printList(tail);
}