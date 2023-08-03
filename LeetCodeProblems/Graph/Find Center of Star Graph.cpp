#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> connected;
        for(auto& e : edges)
        {
            connected[e[0]]++;
            connected[e[1]]++;
        }
        for(auto& [k,v] : connected) if(v==connected.size()-1) return k;
        return -1;
    }
};