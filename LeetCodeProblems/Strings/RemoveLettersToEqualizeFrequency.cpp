#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> a(26,0);
        map<int,int> m;
        for(auto i : word) a[i-'a']++;
        for(auto i : a) if(i!=0) m[i]++;
        if((m.size()==1 && (m.find(1)!=m.end() || m.begin()->second==1)) || (m.size()==2 && ((m.find(1)!=m.end() && m[1]==1) || (m.rbegin()->second==1 && m.rbegin()->first == m.begin()->first+1)))) return true;
        else return false;
    }
};