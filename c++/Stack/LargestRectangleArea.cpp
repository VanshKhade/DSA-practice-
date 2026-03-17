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
/*//Single pass optimized solution
    int LargestRectangleArea(vector<int> heights){
        int n = heights.size();
        stack<int> s;
        int maxArea = 0;
        for(int i =0; i<=n; i++){
            int currheight = (i==n)? 0:heights[i];
            while(!s.empty() && currheight<heights[s.top()]){
                int h = heights[s.top()];
                s.pop();
                int right = i;
                int left = s.empty() ? -1 : s.top();
                int width = right - left -1;
                maxArea = max(maxArea,h*width);
            }
            s.push(i);
        }
        return maxArea;    
    }
    */