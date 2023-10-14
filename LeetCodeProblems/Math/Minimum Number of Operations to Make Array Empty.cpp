#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        int s = 0;
        for(auto& e : nums) m[e]++;
        for(auto& [k,v] : m)
        {
            if(v==1) return -1;
            else
            {
                if(v%3==1)
                {
                    s+=2;
                    v-=4;
                }
                else if(v%3==2)
                {
                    s++;
                    v-=2;  
                }
                s+=v/3;
            }
        }
        return s;
    }
};