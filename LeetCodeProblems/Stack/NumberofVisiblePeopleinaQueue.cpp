#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result(heights.size(),0);
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            int seen = 0;
            while(!st.empty() && heights[i]>st.top())
            {
                seen++;
                st.pop();
            }
            if(!st.empty()) seen++;
            result[i]=seen;
            st.push(heights[i]);
        }
        return result;
    }
};