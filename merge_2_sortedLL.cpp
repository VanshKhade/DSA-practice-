#include<iostream>
using namespace std;
struct node{
    int data;
    node* next;
    node(int val): data(val),next(NULL) {}
};
node* mergeList(node* l1,node* l2){
    if(l2==NULL) return l1;
    if(l1==NULL) return l2;
    node* head = NULL;
    node* tail = NULL;
    if(l1->data < l2->data){
        head = tail = l1;
        l1 = l1->next;
    }
    else{
        head = tail = l2;
        l2 = l2->next;
    }
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        else{
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }
    if(l1!=NULL){
        tail->next = l1;
    }

    if(l2 != NULL){
        tail->next = l2;
    }
    return head;
}
void printList(node* head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}
int main(){

    node* l1 = new node(1);
    l1->next = new node(3);
    l1->next->next = new node(5);

    node* l2 = new node(2);
    l2->next = new node(4);
    l2->next->next = new node(6);

    cout<<"List 1: ";
    printList(l1);

    cout<<"List 2: ";
    printList(l2);

    node* merged = mergeList(l1,l2);

    cout<<"Merged List: ";
    printList(merged);

    return 0;
}
