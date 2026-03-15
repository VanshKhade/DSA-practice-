#include<iostream>
using namespace std;

class TwoStack{
    int *arr;
    int size;
    int top1, top2;

public:

    TwoStack(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int val){
        if(top2 - top1 > 1){
            top1++;
            arr[top1] = val;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void push2(int val){
        if(top2 - top1 > 1){
            top2--;
            arr[top2] = val;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop1(){
        if(top1 >= 0){
            top1--;
        }
        else{
            cout<<"Stack1 Underflow"<<endl;
        }
    }

    void pop2(){
        if(top2 < size){
            top2++;
        }
        else{
            cout<<"Stack2 Underflow"<<endl;
        }
    }
};

int main(){

    TwoStack s(10);

    s.push1(10);
    s.push1(20);
    s.push1(30);

    s.push2(50);
    s.push2(60);
    s.push2(70);

}