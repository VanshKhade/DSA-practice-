#include<iostream>
#include<stack>
using namespace std;
bool FindRedundant(string str){
    stack<char> s;
    for(int i=0; i<str.length(); i++){
        char ch = str[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            s.push(ch);
        }
        else if(ch==')'){
            bool isRedundant = true;
            while(s.top()!='('){
                char top = s.top();
                if(top=='+' || top=='-' || top=='*' || top=='/'){
                    isRedundant = false;
                }
                s.pop();
            }
            s.pop();
            if(isRedundant){
                return true;
            }
        }
    }
    return false;
}
int main(){
    string str = "((a-b))";
    if(FindRedundant(str)){
        cout<<"Redundant Brackets found"<<endl;
    }
    else{
        cout<<"No redundant Brackets"<<endl;
    }
}