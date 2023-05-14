#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        unordered_set<int> s;
        for(auto e : arr) m[e]++;
        for(auto& [key,val] : m)
        {
            if(s.count(val)>0) return false;
            else s.insert(val);
        }
        return true;
    }
};