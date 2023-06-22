#include <vector>
using namespace std;

class Solution {
public:
    bool splitString(string s) {
        return split(s,0);
    }
private:
    bool split(string& s, int start)
    {
        if(start>=s.size() && v.size()>1) return true;
        for(int i=start;i<s.size();i++)
        {
            long long t = convertToLong(s,start,i);
            if(t>99999999999) break;
            if(v.size()==0 || t==v.back()-1)
            {
                v.push_back(t);
                bool res = split(s,i+1);
                if(res) return true;
                v.pop_back();
            }
        }
        return false;
    }
    
    long long convertToLong(string& s, int start, int last)
    {
        long long val = 0;
        for(int i=start;i<=last;i++)
        {
            val*=10;
            val+=(s[i]-'0');
        }
        return val;
    }
    
    vector<long long> v;
};