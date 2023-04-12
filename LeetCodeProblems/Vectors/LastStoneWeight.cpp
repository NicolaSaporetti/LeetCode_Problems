#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int i=stones.size()-1;i>=1;i--)
        {
            sort(stones.begin(),stones.end());
            if(stones[i]==stones[i-1])
            {
                stones.resize(stones.size()-2);
                i--;
            }
            else
            {
                stones[i-1]=stones[i]-stones[i-1];
                stones.resize(stones.size()-1);
            }
        }
        if(stones.size()==0) return 0;
        else return stones[0];
    }
};