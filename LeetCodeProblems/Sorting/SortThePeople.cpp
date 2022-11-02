#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;
        for(int i=0;i<names.size();i++)
        {
            m[heights[i]]=names[i];
        }
        vector<string> res;
        for(auto it=m.rbegin();it!=m.rend();it++)
        {
            res.push_back(it->second);
        }
        return res;
    }
};