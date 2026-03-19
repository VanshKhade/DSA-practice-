#include<iostream>
#include<stack>
using namespace std;
class SpecialStack{
    stack<int> s;
    stack<int> minStack;
public:
    void push(int x){
        s.push(x);
        if(minStack.empty()){
            minStack.push(x);
        }
        else{
            minStack.push(min(x,minStack.top()));
        }
    }
    void pop(){
        if(s.empty()){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        s.pop();
        minStack.pop();
    }
    int top(){
        if(s.empty()){
            return -1;
        }
        return s.top();
    }
    int getMIN(){
        if(minStack.empty()){
            return -1;
        }
        return minStack.top();
    }
};
int main(){
    SpecialStack s;
    s.push(5);
    s.push(3);
    s.push(7);
    s.push(2);
    cout<<"Min: "<<s.getMIN()<<endl;
    s.pop();
    cout<<"Min: "<<s.getMIN()<<endl;

}