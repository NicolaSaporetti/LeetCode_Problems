#include <vector>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> s;
        vector<bool> match(3,false);
        for(int i=0;i<triplets.size();i++) s.insert(i);
        for(int i=0;i<triplets.size();i++)
        {
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2])
            {
                if(triplets[i][0]==target[0]) match[0] = true;
                if(triplets[i][1]==target[1]) match[1] = true;
                if(triplets[i][2]==target[2]) match[2] = true;
            }
            else s.erase(i);
        }
        return (!s.empty() && match[0] && match[1] && match[2]);
    }
};