#include <vector>
using namespace std;

class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        res = INT_MAX;
        kids.assign(k,0);
        kids[0]=jobs[0];
        giveCookies(jobs,1);
        return res;
    }

private:
    void giveCookies(vector<int>& cookies, int num)
    {
        if(num>=cookies.size())
        {
            int maxE = *std::max_element(kids.begin(),kids.end());
            res = min(res,maxE);
        }
        else
        {
            if(*std::max_element(kids.begin(),kids.end())>=res) return;
            bool exit = false;
            for(int i=0;i<kids.size() && !exit;i++)
            {
                kids[i]+=cookies[num];
                giveCookies(cookies,num+1);
                kids[i]-=cookies[num];
                if(kids[i]==0) exit = true;
            }
        }
    }
    
    vector<int> kids;
    int res;
};