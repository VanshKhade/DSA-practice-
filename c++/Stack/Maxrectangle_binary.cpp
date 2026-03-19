#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int LargestRectangleArea(vector<int>& heights){
    int n = heights.size();
    stack<int> s;
    int maxArea = 0;
    for(int i=0 ; i<=n ; i++){
        int curr = (i==n) ? 0 : heights[i];
        while(!s.empty() && curr<heights[s.top()]){
            int h = heights[s.top()];
            s.pop();
            int right = i;
            int left = s.empty() ? -1 : s.top();
            int width = right - left -1;
            maxArea = max(maxArea , h*width);
        }
        s.push(i);
    }
    return maxArea;                                                                                                               
}
int maxRectangle(vector<vector<int>>& matrix){
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int> height(col,0);
    int maxArea = 0;
    for(int i= 0 ; i<row ; i++){
        for(int j=0 ; j<col ; j++){
            if(matrix[i][j]==1){
                height[j]++;
            }
            else{
                height[0] = 0;
            }
        }
        maxArea = max(maxArea , LargestRectangleArea(height));
    }
    return maxArea;
}
int main(){
    vector<vector<int>> matrix = {{1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
    cout<<"Max Rectangle Area: "<< maxRectangle(matrix)<<endl;
}