#include <vector>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        set<int> avaO;
        set<int> avaE;
        this->k = k;
        this->n = n;
        r.assign(n,-1);
        for(int i=0;i<n;i++)
        {
            if(i%2) avaO.insert(i);
            else avaE.insert(i);
        }
        for(auto e : banned)
        {
            if(e%2) avaO.erase(e);
            else avaE.erase(e);
        }
        q.push(p);
        if(p%2) avaO.erase(p);
        else avaE.erase(p);
        r[p]=0;
        cost = 1;
        if(k==1) return r;
        minD = (k%2)? 2 : 1;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                int pos = q.front();
                q.pop();
                if(k%2==pos%2) addElements(avaO,pos);
                else addElements(avaE,pos);
            }
            cost++;
        }
        return r;
    }
private:
    void addElements(set<int>& ava, int pos)
    {
        int lv = pos+minD;
        int dist = 0;
        for(auto it = ava.lower_bound(lv);it!=ava.end() && *it<pos+k;)
        {
            dist = (k-(*it-pos+1))/2;
            if(pos-dist>=0 && *it+dist<n)
            {
                q.push(*it);
                r[*it]=cost;
                ava.erase(it++);
            }
            else it++;
        }
        lv = pos-k+1;
        for(auto it = ava.lower_bound(lv);it!=ava.end() && *it+minD<=pos;)
        {
            dist = (k-(pos-*it+1))/2;
            if(*it-dist>=0 && pos+dist<n)
            {
                q.push(*it);
                r[*it]=cost;
                ava.erase(it++);
            }
            else it++;
        }
    }

    vector<int> r;
    queue<int> q;
    int minD;
    int cost;
    int n;
    int k;
};