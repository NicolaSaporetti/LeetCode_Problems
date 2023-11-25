#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string,vector<int>> m;
        vector<string> res;
        for(auto e : access_times) m[e[0]].push_back(stoi(e[1]));
        for(auto & [k,v] : m)
        {
            cout<<k<<endl;
            sort(begin(v),end(v));
            for(int i=2;i<v.size();i++)
            {
                if(isWithin(v[i-1],v[i]) && isWithin(v[i-2],v[i]))
                {
                    res.push_back(k);
                    break;
                }
            }
        }
        return res;
    }
private:
    bool isWithin(int n1, int n2)
    {
        int h1 = n1/100;
        int m1 = n1%100;
        int h2 = n2/100;
        int m2 = n2%100;
        return (h1==h2 || (h2==h1+1 && m2<m1));
    }
};