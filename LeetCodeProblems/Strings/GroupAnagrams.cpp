#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;

class Solution {
private:
    map<array<int,26>,int> myM;
    vector<vector<string>> results;
    
    void resetBase(array<int,26>& base)
    {
        for(int i=0;i<26;i++) base[i]=0;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        array<int,26> base;
        for(int i=0;i<strs.size();i++)
        {
            resetBase(base);
            for(int j=0;j<strs[i].size();j++)
            {
                base[strs[i][j]-'a']++;
            }
            auto it=myM.find(base);
            if(it!=myM.end())
            {
                results[it->second].push_back(strs[i]);
            }
            else
            {
                vector<string> a;
                a.push_back(strs[i]);
                results.push_back(a);
                myM.insert(pair<array<int,26>,int>(base,results.size()-1));
            }
        }
        if(results.empty())
        {
            vector<string> b;
            results.push_back(b);
        }
        return results;
    }
};