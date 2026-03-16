#include<iostream>
#include<stack>
using namespace std;
int FindMinimumCost(string str){
    if(str.length()%2==1){
        return -1;
    }
    stack<char> s;
    for(int i = 0; i<str.length() ; i++){
        char ch = str[i];
        if(ch=='{'){
            s.push(ch);
        }
        else{
            if(!s.empty() && s.top()=='{'){
                s.pop();
            }
            else{
                s.push(ch);
            }
        }
    }
    int a = 0 , b = 0;
    while(!s.empty()){
        if(s.top()=='{')
            a++;
        else
            b++;
        s.pop();
    }
    return (a+1)/2 + (b+1)/2;
}
int main(){
    string str = "}{{}}{{{";
    cout<<"Minimum cost: "<<FindMinimumCost(str)<<endl;
}