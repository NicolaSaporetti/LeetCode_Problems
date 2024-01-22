#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long  beautifulSubstrings(string s, int k) {
        long long res = 0;
        int sz = s.size();
        unordered_map<int,unordered_map<int,long long>> m;
        m[0][0]=1;
        int voc = 0;
        int con = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||  s[i]=='o' || s[i]=='u') voc++;
            else con++;
            int dif = voc-con;
            int sec = voc%k;
            if(m.count(dif)>0)
            {
                for(auto& [key,v] : m[dif]) if((voc-key)*(voc-key)%k==0) res+=v;
            }
            m[dif][sec]++;
        }
        return res;
    }
};