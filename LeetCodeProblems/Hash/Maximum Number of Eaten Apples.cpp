#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int eatenApples(vector<int>& apples, vector<int>& days) {
        map<int,int> m;
        int d = 0;
        int sz = days.size();
        int i=0;
        for(;i<sz;i++)
        {
            //cout<<"I: "<<i<<endl;
            if(m.count(i)>0) m.erase(i);
            if(apples[i]>0) m[i+days[i]]+=apples[i];
            if(!m.empty())
            {
                d++;
                m.begin()->second--;
                if(m.begin()->second==0) m.erase(m.begin());
            }
            //for(auto& [k,v]: m) cout<<k<<" "<<v<<endl;
            //cout<<endl;
        }
        while(!m.empty())
        {
            //cout<<"I: "<<i<<endl;
            if(m.count(i)>0) m.erase(i);
            if(!m.empty())
            {
                d++;
                m.begin()->second--;
                if(m.begin()->second==0) m.erase(m.begin());
            }
            //for(auto& [k,v]: m) cout<<k<<" "<<v<<endl;
            //cout<<endl;
            i++;
        }
        return d;
    }
};