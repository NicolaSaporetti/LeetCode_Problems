#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        int sz = maxHeights.size();
        vector<long long> left(sz+1,0);
        vector<long long> right(sz+1,0);
        long long res = 0;
        stack<pair<long long,long long>> st;
        long long sum = 0;
        for(int i=0;i<sz;i++)
        {
            long long n=0;
            while(!st.empty() && maxHeights[i]<st.top().first)
            {
                sum-=(st.top().first*st.top().second);
                n+=st.top().second;
                st.pop();
            }
            st.push({maxHeights[i],n+1});
            sum+=(maxHeights[i]*(n+1));
            res = max(res,sum);
            left[i+1]=sum;
        }
        st = {};
        sum=0;
        for(int i=sz-1;i>=0;i--)
        {
            long long n=0;
            while(!st.empty() && maxHeights[i]<st.top().first)
            {
                sum-=(st.top().first*st.top().second);
                n+=st.top().second;
                st.pop();
            }
            st.push({maxHeights[i],n+1});
            sum+=(maxHeights[i]*(n+1));
            res = max(res,sum);
            right[i]=sum;
        }
        for(int i=0;i<=sz;i++)
        {
            res = max(res,left[i]+right[i]);
        }
        return res;
    }
};