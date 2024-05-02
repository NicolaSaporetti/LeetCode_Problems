#include <vector>
using namespace std;

class Solution {
public:
    int addMinimum(string word) {
        char prev = 'c';
        vector<char> p{'c','a','b'};
        vector<char> n{'b','c','a'};
        int r = 0;
        for(auto e : word)
        {
            while(prev!=p[e-'a'])
            {
                prev = n[prev-'a'];
                r++;
            }
            prev=e;
        }
        while(prev!='c')
        {
            prev = n[prev-'a'];
            r++;
        }
        return r;
    }
};