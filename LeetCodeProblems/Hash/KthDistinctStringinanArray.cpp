#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        map<string,bool> m;
        for(auto& s : arr)
        {
            if(m.count(s)==0) m[s]=true;
            else m[s]=false;
        }
        for(auto& s : arr)
        {
            if(m[s]) k--;
            if(k==0) return s;
        }
        return "";
    }
};