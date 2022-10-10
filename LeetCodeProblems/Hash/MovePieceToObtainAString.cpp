#include <map>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        map<int,char> s;
        map<int,char> e;
        for(int i=0;i<start.size();i++)
        {
            if(start[i]=='L') s[i]='L';
            else if(start[i]=='R') s[i]='R';
            if(target[i]=='L') e[i]='L';
            else if(target[i]=='R') e[i]='R';
        }
        for(auto it = s.begin();it!=s.end();it++)
        {
            if(e.empty()) return false;
            if(it->second =='L')
            {
                if(e.begin()->second =='R' || e.begin()->first > it->first) return false;
            }
            else
            {
                if(e.begin()->second =='L' || e.begin()->first < it->first) return false;
            }
            e.erase(e.begin());
        }
        if(!e.empty()) return false;
        return true;
    }
};