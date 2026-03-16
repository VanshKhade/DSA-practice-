#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num = s.top();
    s.pop();
    insertAtBottom(s,x);
    s.push(num);
}
int main(){
    stack<int> s;
    s.push(1);
    s.push(6);
    s.push(2);
    s.push(12);
    insertAtBottom(s,0);
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}