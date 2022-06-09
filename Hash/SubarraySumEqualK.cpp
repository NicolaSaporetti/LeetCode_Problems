class Solution {
    unordered_map<int,int> myM;
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans =0;
        vector<int> arr(nums.size(),0);
        arr[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            arr[i]=arr[i-1]+nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(arr[i] == k) ans++;
            if(myM.find(arr[i] - k) != myM.end())
            {
                ans += myM[arr[i] - k];
            }
            myM[arr[i]]++;
        }
        return ans;
    }
};