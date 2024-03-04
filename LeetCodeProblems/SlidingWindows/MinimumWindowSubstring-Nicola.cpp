#include <vector>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> v(58,0);
        vector<int> v1(58,0);
        for(auto e : t) v[e-'A']++;
        int start = 0;
        int dim = INT_MAX;
        string r;
        for(int i=0;i<s.size();i++)
        {
            v1[s[i]-'A']++;
            if(match(v,v1))
            {
                while(match(v,v1)) v1[s[start++]-'A']--;
                v1[s[--start]-'A']++;
                if(i-start+1<dim)
                {
                    dim = i-start+1;
                    r = s.substr(start, dim);
                }
            }
        }
        return r;
    }
private:
    bool match(vector<int>& v, vector<int>& v1)
    {
        for(int i=0;i<58;i++) if(v1[i]<v[i]) return false;
        return true;
    }
};