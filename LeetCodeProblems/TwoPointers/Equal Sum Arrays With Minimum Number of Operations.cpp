#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int v = accumulate(begin(nums1),end(nums1),0)-accumulate(begin(nums2),end(nums2),0);
        return (v>0)? change(nums1,nums2,v) : change(nums2,nums1, -v);
    }

    int change(vector<int>& nums1, vector<int>& nums2, int v)
    {
        int res = 0;
        int p1 = nums1.size()-1;
        int p2 = 0;
        while(v>0 && (p1>=0 || p2<nums2.size()))
        {
            if(p2>=nums2.size() || (p1>=0 && nums1[p1]-1>=6-nums2[p2]))
            {
                v-=nums1[p1]-1;
                p1--;
            }
            else
            {
                v-=6-nums2[p2];
                p2++;
            }
            res++;
        }
        return (v>0)? -1 : res;
    }
};