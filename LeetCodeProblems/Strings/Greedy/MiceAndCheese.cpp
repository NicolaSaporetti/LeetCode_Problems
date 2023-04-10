#include <vector>
#include <multiset>
using namespace std;

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int sz = reward1.size();
        int sum = 0;
        multiset<int> s;
        for(int i=0;i<sz;i++)
        {
            s.insert(reward1[i]-reward2[i]);
            if(s.size()>k)
            {
                s.erase(s.begin());
            }
            sum+=reward2[i];
        }
        for(auto& e : s) sum+=e;
        return sum;
    }
};