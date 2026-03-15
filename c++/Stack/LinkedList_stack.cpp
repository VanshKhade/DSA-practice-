#include<iostream>
using namespace std;
class Stack{
public:
    class Node{
    public:
        int data;
        Node* next;
    };

    Node* top;
    Stack(){
        top = NULL;
    }
    void push(int val){
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }
    void pop(){
        if(top == NULL){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    int peek(){
        if(top == NULL){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){
        return top == NULL;
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<"TOP element: "<<s.peek()<<endl;
    s.pop();
    cout<<"Top after pop: "<<s.peek()<<endl;
    if(s.isEmpty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
}