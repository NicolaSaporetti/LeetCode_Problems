#include <vector>
using namespace std;

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int sz = garbage.size();
        vector<int> v(3,0);
        for(int i=sz-1;i>=0;i--)
        {
            for(auto& e : garbage[i])
            {
                if(e=='G') v[0]++;
                else if(e=='P') v[1]++;
                else v[2]++;  
            }
            for(int j=0;j<3;j++)
            {
                if(v[j]>0 && i!=0) v[j]+=travel[i-1];
            }
        }
        return v[0]+v[1]+v[2];

    }
};