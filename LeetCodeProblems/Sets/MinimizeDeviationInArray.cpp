#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int result = 0;
        set<int> s;
        for(auto& e : nums)
        {
            if(e%2==0) s.insert(e);
            else s.insert(e*2);
        }
        result = *s.rbegin()-*s.begin();
        for(auto it = s.rbegin();it!=s.rend();)
        {
            if(*it%2==1) break;
            s.insert(*it/2);
            s.erase(next(it).base()++);
            result = min(result,*s.rbegin()-*s.begin());
        }
        for(auto it = s.begin();it!=s.end();)
        {
            if(*it%2==0) break;
            s.insert(*it*2);
            s.erase(it++);
            result = min(result,*s.rbegin()-*s.begin());
        }
        return result;
    }
};