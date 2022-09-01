#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res(spells.size(),0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            long long value = success/spells[i];
            if(success%spells[i]!=0) value++;
            int element = lower_bound(potions.begin(),potions.end(),value)-potions.begin();
            res[i] = potions.size()-element;
        }
        return res;
    }
};