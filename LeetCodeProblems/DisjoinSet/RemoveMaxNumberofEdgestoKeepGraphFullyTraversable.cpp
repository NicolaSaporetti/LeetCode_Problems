#include <vector>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjoinSetUnion alice(n);
        DisjoinSetUnion bob(n);
        
        int tot = 0;
        for(auto& e : edges)
        {
            if(e[0]==3)
            {
                if(alice.are_connect(e[1]-1,e[2]-1)) tot++;
                else
                {
                    alice.connect(e[1]-1,e[2]-1);
                    bob.connect(e[1]-1,e[2]-1);
                }
            }
        }
        for(auto& e : edges)
        {
            if(e[0]==1)
            {
                if(alice.are_connect(e[1]-1,e[2]-1)) tot++;
                else alice.connect(e[1]-1,e[2]-1);
            }
            else if(e[0]==2)
            {
                if(bob.are_connect(e[1]-1,e[2]-1)) tot++;
                else bob.connect(e[1]-1,e[2]-1);
            }
        }
        int alice_base_root = alice.find_set(0);
        for(int i=1;i<n;i++) if(alice.find_set(i)!=alice_base_root) return -1;
        int bob_base_root = bob.find_set(0);
        for(int i=1;i<n;i++) if(bob.find_set(i)!=bob_base_root) return -1;
        return tot;
    }
};