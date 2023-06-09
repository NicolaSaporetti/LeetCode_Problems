class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<bool> num(51,false);
        for(auto& r : ranges)
        {
            for(int i=r[0];i<=r[1];i++)
            {
                num[i]=true;
            }
        }
        for(int i=left;i<=right;i++) if(num[i]==false) return false;
        return true;
    }
};