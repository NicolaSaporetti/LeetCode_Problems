#include <vector>
using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        vector<bool> v(31,0);
        for(auto& e : nums) for(int i=0;i<31;i++) if(e==(1<<i)) v[i]=true;
        for(int i=0;i<31;i++)
        {
            if(!v[i]) return (1<<i);
        }
        return -1;
    }
};