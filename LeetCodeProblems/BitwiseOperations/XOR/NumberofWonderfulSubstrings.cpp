#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        int r = 0;
        long long res = 0;
        unordered_map<int,int> m;
        m[0]=1;
        for(auto c : word)
        {
            r^=(1<<(c-'a'));
            res+=(long long)m[r];
            for(int i=0;i<10;i++) res+=(long long)m[r^(1<<i)];
            m[r]++;
        }
        return res;
    }
};