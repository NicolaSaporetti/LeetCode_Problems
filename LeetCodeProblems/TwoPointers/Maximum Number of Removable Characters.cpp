#include <vector>
using namespace std;

class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int min=0;
        int max=removable.size();
        int res =0;
        while(min<=max)
        {
            int avg = min+(max-min)/2;
            if(isSubsequence(s,p,avg,removable))
            {
                res = avg;
                min = avg+1;
            }
            else max = avg-1;
        }
        return res;
    }
private:
    bool isSubsequence(string s, string& p, int num, vector<int>& removable)
    {
        for(int i=0;i<num;i++) s[removable[i]] = '*';
        int pos = 0;
        for(auto& c : s) if(c!='*') s[pos++]=c;
        s.resize(pos);
        int point = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==p[point]) point++;
            if(point==p.size()) return true;
        }
        return false;
    }
};