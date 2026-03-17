#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> nextSmaller(vector<int>arr, int n){
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1 ; i>=0; i--){
        int curr = arr[i];
        while(s.top() != -1 && arr[s.top()]>= curr){
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> prevSmaller(vector<int>arr,int n){
   stack<int> s;
   s.push(-1);
   vector<int> ans(n);
   for(int i = 0 ; i < n; i++){
    int curr = arr[i];
    while(s.top() != -1 && arr[s.top()] >= curr){
        s.pop();
    }
    ans[i] = s.top();
    s.push(i);
   }
   return ans;
}   
int largestRectangleArea(vector<int> heights){  
    int n = heights.size();
    vector<int> prev = prevSmaller(heights,n);
    vector<int> next = nextSmaller(heights,n);
    int area = 0;
    for(int i= 0 ; i< n; i++){
        int length = heights[i];
        if(next[i] == -1){
            next[i] == n;
        }
        int width = next[i] - prev[i] - 1;
        int currArea = length * width;
        area = max(area, currArea);
    }
    return area;
  
}
int main(){
    vector<int> heights = {2,1,5,6,2,3};
    cout<<"Largest Area: "<<largestRectangleArea(heights)<<endl;
}