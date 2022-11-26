#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector <int> left(n,-1),right(n,n);
        int mod=1e9+7;
        long long ans=0;
        stack <int> s;
        for (int i=n-1;i>=0;i--){
            while (!s.empty() && arr[s.top()]>=arr[i]) s.pop();
            if (!s.empty()) right[i]=s.top();
            s.push(i);
        }
        s = {};
        for (int i=0;i<n;i++){
            while (!s.empty() && arr[s.top()]>arr[i]) s.pop();
            if (!s.empty()) left[i]=s.top();
            s.push(i);
        }
        for (int i=0;i<n;i++){
            ans += (long long)((right[i]-i)*(i-left[i]))*(long long)arr[i];
            ans %= mod;
        }
        return ans;  
    }
};