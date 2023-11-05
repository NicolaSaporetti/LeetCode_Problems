#include <stack>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int j=0;
        for(int i=1;i<=n && j<target.size();i++)
        {
            res.push_back("Push");
            if(i<target[j]) res.push_back("Pop");
            if(i==target[j]) j++;
        }
        return res;
    }
};