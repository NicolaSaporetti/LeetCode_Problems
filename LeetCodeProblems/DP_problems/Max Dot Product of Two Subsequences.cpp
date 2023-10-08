#include <vector>
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        sz1 = nums1.size();
        sz2 = nums2.size();
        dp.assign(sz1+1,vector<int>(sz2+1,INT_MIN));
        if(count_if(begin(nums1),end(nums1),[](int e){return e<0;}) == sz1 &&
           count_if(begin(nums2),end(nums2),[](int e){return e>0;}) == sz2)
            return *max_element(begin(nums1),end(nums1))* *min_element(begin(nums2),end(nums2));
        if(count_if(begin(nums1),end(nums1),[](int e){return e>0;}) == sz1 &&
           count_if(begin(nums2),end(nums2),[](int e){return e<0;}) == sz2)
            return *min_element(begin(nums1),end(nums1))* *max_element(begin(nums2),end(nums2));
        return compute(nums1,nums2,0,0);
    }
private:
    int compute(vector<int>& nums1, vector<int>& nums2, int n1, int n2)
    {
        if(n1>=sz1 || n2>=sz2) return 0;
        else if(dp[n1][n2]!=INT_MIN) return dp[n1][n2];
        else
        {
            int val = nums1[n1]*nums2[n2]+compute(nums1,nums2,n1+1,n2+1);
            int val2 = compute(nums1,nums2,n1,n2+1);
            int val3 = compute(nums1,nums2,n1+1,n2);
            int maxv = max(max(val,dp[n1+1][n2+1]),max(val2,val3));
            return dp[n1][n2]=maxv;
        }
    }

    vector<vector<int>> dp;
    int sz1;
    int sz2;
};