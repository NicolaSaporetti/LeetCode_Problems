#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int sz;
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        sz = rocks.size();
        int total = 0;
        for(int i=0;i<sz;i++)
        {
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        for(int i=0;i<sz&&additionalRocks>0;i++)
        {
            if(capacity[i]>0)
            {
                if(capacity[i]<=additionalRocks)
                {
                    additionalRocks-=capacity[i];
                    capacity[i]=0;
                    total++;
                }
                else
                {
                    capacity[i]-=additionalRocks;
                    additionalRocks-=0;
                }
            }
            else total++;
        }
        return total;
    }
};

int main()
{
    Solution solution;
    return 0;
}