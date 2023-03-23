#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int sz = nums.size();
        map<int, int> m;
        for(int i=0;i<sz;i++)
        {
            m[(nums[i]%value+value)%value]++;
        }
        bool isFound = false;
        int num = -1;
        do
        {
            num++;
            isFound = false;
            if(m[num%value]>0)
            {
                isFound = true;
                m[num%value]--;
            }
        } while(isFound);
        return num;
    }
};