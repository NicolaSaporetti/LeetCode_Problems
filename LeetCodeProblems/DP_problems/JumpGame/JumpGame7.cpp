#include <set>
#include <queue>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        sz = s.size();
        for(int i=1;i<sz;i++) if(s[i]=='0') ava.insert(i);
        q.push(0);
        return compute(minJump,maxJump);
    }
private:
    bool compute(int minJump, int maxJump)
    {
        while(!q.empty())
        {
            int el = q.front();
            q.pop();
            if(el==sz-1) return true;
            for(auto it = ava.lower_bound(el+minJump); it!=ava.end() && *it<=el+maxJump; ava.erase(it++))
            {
                q.push(*it);
            }
            
        }
        return false;
    }
    set<int> ava;
    int sz;
    queue<int> q;
};