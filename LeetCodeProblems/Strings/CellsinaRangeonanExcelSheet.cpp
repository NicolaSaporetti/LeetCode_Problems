#include <vector>
using namespace std;

class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> res;
        for(int i=s[0];i<=s[3];i++)
        {
            for(int j=s[1];j<=s[4];j++)
            {
                res.push_back({char(i),char(j)});
            }
        }
        return res;
    }
};