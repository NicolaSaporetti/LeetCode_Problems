#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> leftSmall(heights.size());
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) leftSmall[i]=0;
            else leftSmall[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        
        vector<int> rightSmall(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(st.empty()) rightSmall[i]=heights.size()-1;
            else rightSmall[i]=st.top()-1;
            st.push(i);
        }
        
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi = max(maxi,heights[i]*(rightSmall[i]-leftSmall[i]+1));
        }
        return maxi;
    }
};