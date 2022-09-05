#include <vector>
using namespace std;

class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        unfa = INT_MAX;
        kids.assign(k,0);
        kids[0]=cookies[0];
        giveCookies(cookies,1);
        return unfa;
    }

private:
    void giveCookies(vector<int>& cookies, int num)
    {
        if(num>=cookies.size())
        {
            int minE = *std::min_element(kids.begin(),kids.end());
            int maxE = *std::max_element(kids.begin(),kids.end());
            unfa = min(unfa,maxE);
        }
        else
        {
            bool exit = false;
            for(int i=0;i<kids.size() && !exit;i++)
            {
                if(kids[i]==0) exit = true;
                kids[i]+=cookies[num];
                giveCookies(cookies,num+1);
                kids[i]-=cookies[num];
            }
        }
    }
    
    vector<int> kids;
    int unfa;
};