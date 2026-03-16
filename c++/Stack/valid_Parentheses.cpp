#include<iostream>
#include<stack>
using namespace std;
bool isValid(string str){
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch=='{' || ch=='[' || ch=='('){
            s.push(ch);
        }
        else{
            if(s.empty()){
                return false;
            }
            int top = s.top();
            if((ch=='}' && top=='{') || (ch==']' && top=='[') || (ch ==')' && top=='(')){
                s.pop();
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}
int main(){
    string str = "[]{})";
    if(isValid(str)){
        cout<<"valid parentheses"<<endl;
    }
    else{
        cout<<"Invalid parentheses"<<endl;
    }
}