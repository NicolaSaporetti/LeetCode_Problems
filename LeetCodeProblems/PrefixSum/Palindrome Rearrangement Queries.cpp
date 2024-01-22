#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<bool> canMakePalindromeQueries(string s, vector<vector<int>>& queries) {
        sz = s.size();
        vector<int> v1(26,0);
        v.push_back(v1);
        for(auto e : s)
        {
            v1[e-'a']++;
            v.push_back(v1);
        }
        for(int i=0;i<sz/2;i++) if(s[i]!=s[sz-1-i]) st.insert(i);
        vector<bool> r;
        for(auto e : queries)
        {
            bool res = true;
            for(int i=0;i<26 && res;i++)
                if(v[sz/2][i]*2!=v[sz][i])
                {
                    res = false;
                    r.push_back(res);
                }
            if(res)
            {
                s1.assign(26,0);
                s2.assign(26,0);
                for(int i=0;i<26;i++)
                {
                    s1[i]=v[e[1]+1][i]-v[e[0]][i];
                    s2[i]=v[e[3]+1][i]-v[e[2]][i];
                }
                r.push_back(query(s,e));
            }
        } 
        return r;
    }
private:
    bool query(string& s, vector<int>& queries)
    {
        bool res = true;
        int i0=sz-1-queries[3];
        int i1=sz-1-queries[2];
        int d0=sz/2-1-i1;
        int d1=sz/2-1-queries[1];
        res&=compareFix(0,min(i0,queries[0]));
        res&=compareFix(max(i1,queries[1])+1,min(d0,d1));
        int dist = max(i0,queries[0])+max(d0,d1)-sz/2;
        if(dist>0) res&=compareFix(max(i0,queries[0])-dist,dist);
        if((queries[0]<=i0 && queries[1]>=i0) || (queries[0]>=i0 && queries[0]<=i1))
        {
            if(queries[0]<i0) res&=verify(queries[0],i0-queries[0],0);
            else if(i0<queries[0])  res&=verify(i0,queries[0]-i0,1);
            if(queries[1]>i1)  res&=verify(i1+1,queries[1]-i1,0);
            else if(i1>queries[1])  res&=verify(queries[1]+1,i1-queries[1],1);
        }
        else
        {
            res&=verify(queries[0],queries[1]-queries[0]+1,0);
            res&=verify(i0,i1-i0+1,1);
        }
        return res;
    }
    
    bool compareFix(int start,int dist)
    {
        if(dist>0)
        {
            auto it = st.lower_bound(start);
            if(it!=st.end() && *it<=start+dist-1) return false;
        }
        return true;
    }
    
    bool compareFlex(int start,int dist,int set)
    {
        for(int i =0;i<26;i++)
        {
            if(set==0)
            {
                int num = v[sz-start][i]-v[sz-(start+dist)][i];
                s1[i]-=num;
                if(s1[i]<0) return false;
            }
            else
            {
                int num = v[start+dist][i]-v[start][i];
                s2[i]-=num;
                if(s2[i]<0) return false;
            }
        }
        return true;
    }
    
    int sz;
    vector<vector<int>> v;
    set<int> st;
    vector<int> s1;
    vector<int> s2;
};