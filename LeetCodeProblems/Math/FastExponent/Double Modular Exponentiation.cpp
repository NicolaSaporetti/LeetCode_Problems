#include "../../Structures/binpow.cpp"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> v;
        int i=0;
        for(auto e : variables)
        {
            long long v1 = binpowWithModulo(e[0],e[1],10);
            long long v2 = binpowWithModulo(v1,e[2],e[3]);
            if(v2==target) v.push_back(i);
            i++;
        }
        return v;
    }
};