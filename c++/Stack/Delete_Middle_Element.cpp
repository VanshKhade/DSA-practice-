#include<iostream>
#include<stack>
using namespace std;
void solve(stack<int>&st,int count,int size){
    if(count== size/2){
        st.pop();
        return;
    }
    int num = st.top();
    st.pop();
    solve(st,count+1,size);
    st.push(num);
}
void deleteMiddle(stack<int>&st,int size){
    int count = 0 ;
    solve(st,count,size);
}

int main(){
   stack<int> st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
   st.push(6);
   deleteMiddle(st,st.size());
   while(st.size()){
    cout<<st.top()<<" ";
    st.pop();
   }
   cout<<endl;

}
/*//Auxiliary stack method
void deletemiddle(stack<int>& st){
    stack<int> temp;
    int n = st.size();
    int mid = n/2;
    for(int i = 0; i< mid; i++){
        temp.push(st.top());
        st.pop();
    }
    st.pop();
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}*/