#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char,vector<int>> m;
        unordered_map<char,unordered_set<char>> dep;
        unordered_map<char,int> in;
        for(int i=0;i<s.size();i++) m[s[i]].push_back(i);
        for(auto [k,v] : m)
        {
            unordered_set<char> se;
            dep[k]=se;
            for(int i=1;i<v.size();i++)
                for(int j=v[i-1]+1;j<v[i];j++) dep[k].insert(s[j]);
            for(auto e : dep[k]) in[e]++;
        }
        unordered_set<char> ava;
        queue<char> q;
        for(auto [k,v] :dep)
        {
            ava.insert(k);
            if(in[k]==0 && !dep[k].empty()) q.push(k);
        }
        while(!q.empty())
        {
            char el = q.front();
            q.pop();
            for(auto e : dep[el])
            {
                in[e]--;
                if(in[e]==0) q.push(in[e]);
            }
            ava.erase(el);
        }
        vector<unordered_set<char>> comb;
        for(auto it = ava.begin();it!=ava.end();)
        {
            if(dep[*it].empty())
            {
                unordered_set<char> s;
                s.insert(*it);
                comb.push_back(s);
                ava.erase(it++);
            }
            else it++;
        }
        for(auto it = ava.begin();it!=ava.end();ava.erase(it++))
        {
            unordered_set<char> s;
            s.insert(*it);
            queue<char> q;
            q.push(*it);
            bool correct = true;
            while(!q.empty())
            {
                char el = q.front();
                q.pop();
                for(auto elem : dep[el])
                {
                    if(s.find(elem)==s.end() && ava.find(elem)==ava.end()) correct = false;
                    else if(ava.find(elem)!=ava.end() && s.find(elem)==s.end())
                    {
                        s.insert(elem);
                        ava.erase(elem);
                        q.push(elem);
                    }
                }
            }
            if(correct) comb.push_back(s);
        }
        vector<string> r;
        for(auto e : comb)
        {
            int minS = s.size();
            int maxS = 0;
            for(auto l : e)
            {
                minS = min(minS, m[l][0]);
                maxS = max(maxS, m[l].back());
            }
            r.push_back(s.substr(minS,maxS-minS+1));
        }
        return r;
    }
};