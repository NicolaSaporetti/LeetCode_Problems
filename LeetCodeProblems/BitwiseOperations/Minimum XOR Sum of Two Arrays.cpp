#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        sz = nums1.size();
        res = INT_MAX;
        compute(nums1,nums2,0,0,0);
        return res;
    }
private:
    void compute(vector<int>& num1, vector<int>& num2, int pos, int val, int mask)
    {
        if(m.count(mask)>0 && m[mask]<=val) return;
        else
        {
            m[mask]=val;
            if(pos==sz)
            {
                res = min(res,val);
            }
            else
            {
                for(int i=0;i<sz;i++)
                {
                    if(num1[i]!=-1)
                    {
                        int t = num1[i];
                        num1[i]=-1;
                        compute(num1,num2,pos+1,val+(t^num2[pos]),mask|(1<<i));
                        num1[i]=t;
                    }
                }
            }
        }
    }
    
    map<int,int> m;
    int sz;
    int res;
};