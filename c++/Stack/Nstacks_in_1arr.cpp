#include<iostream>
#include<stack>
using namespace std;
class Nstack{
    int *arr, *top , *next;
    int n ,size;
    int freespot;
public:
    Nstack(int N , int S){
        n = N;
        size = S;
        arr = new int[S];
        top = new int[N];
        next = new int[S];
        for(int i=0 ; i<N ;i++){
            top[i] = -1;
        }
        for(int i =0 ; i<S ; i++){
            next[i] = i+1;
        }
        next[S-1] = -1;
        freespot = 0;
    }
    bool push(int x ,int m){
        if(freespot == -1){
            cout<<"Stack Overflow"<<endl;
            return false;
        }
        int index = freespot;
        freespot = next[index];
        arr[index] = x;
        next[index] = top[m-1];
        top[m-1] = index;
        return true;
    }
    int pop(int m){
        if(top[m-1] == -1){
            cout<<"stack underflow"<<endl;
            return -1;
        }
        int index = top[m-1];
        top[m-1] = next[index];
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};
int main(){
    Nstack s(3,6);
    s.push(10,1);
    s.push(20,1);
    s.push(30,2);
    s.push(40,3);
    cout<<s.pop(1)<<endl;
    cout<<s.pop(2)<<endl;

}