#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int mod = 1e9+7;
        long long res = 0;
        vector<long long> left(n,n-1);
        vector<long long> right(n,0);
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            while(!s.empty() && arr[s.top()]>arr[i])
            {
                left[s.top()]=i-1;
                s.pop();
            }
            s.push(i);
        }
        s={};
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && arr[s.top()]>=arr[i])
            {
                right[s.top()]=i+1;
                s.pop();
            }
            s.push(i);
        }
        for(int i=0;i<n;i++)
        {
            res=(res+((left[i]-i+1)*(i-right[i]+1))*arr[i])%mod;
        }
        return res;  
    }
};