#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result;
        vector<int> prev={1};
        vector<int> next;
        for(int i=1;i<n;i++)
        {
            int num = 1;
            for(int j=1;j<prev.size();j++)
            {
                if(prev[j]!=prev[j-1])
                {
                    next.push_back(num);
                    next.push_back(prev[j-1]);
                    num=1;
                }
                else num++;
            }
            next.push_back(num);
            next.push_back(prev[prev.size()-1]);
            prev = std::move(next);
        }
        for(auto i : prev)
        {
            result.push_back(i+'0');
        }
        return result;
    }
};