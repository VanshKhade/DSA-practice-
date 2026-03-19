#include<iostream>
#include<vector>
#include<stack>
using namespace std;
bool knows(vector<vector<int>>& M, int a, int b){
    return M[a][b] == 1;
}
int celebrity(vector<vector<int>>& M, int n){
    stack<int> s;
    for(int i = 0; i < n; i++){
        s.push(i);
    }
    while(s.size() > 1){
        int a = s.top(); s.pop();
        int b = s.top(); s.pop();
        if(knows(M, a, b)){
            s.push(b);
        }
        else{
            s.push(a);
        }
    }
    int candidate = s.top();
    for(int i = 0; i < n; i++){
        if(i != candidate){
            if(M[candidate][i] == 1 || M[i][candidate] == 0){
                return -1;
            }
        }
    }
    return candidate;
}
int main(){
    vector<vector<int>> M = {{0,1,1},{0,0,0},{0,1,0}};
    int n = 3;
    int ans = celebrity(M, n);
    if(ans == -1){
        cout<<"No Celebrity"<<endl;
    } else {
        cout<<"Celebrity is: "<<ans<<endl;
    }
}
/*//NO STACK
    int celebrity(vector<vector<int>> M,int n){
        int a = 0 , b = n -1;
        while(a<b){
            if(M[a][b]==1){
                a++;
            }
            else{
                b--;
            }
        }
        int candidate =  a;
        for(int i= 0 ; i< n; i++){
            if(i!=  candidate){
                if(M[i][candidate]==0  || M[candidate][i] == 1){
                    return -1;
                }
            }
        }
        return candidate;
    }   
*/