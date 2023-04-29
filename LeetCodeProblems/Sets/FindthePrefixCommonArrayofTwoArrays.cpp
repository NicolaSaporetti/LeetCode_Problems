#include <unordered_multiset>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int tot = 0;
        vector<int> res;
        unordered_multiset<int> s1;
        unordered_multiset<int> s2;
        int sz = A.size();
        for(int i=0;i<sz;i++)
        {
            if(A[i]==B[i]) tot++;
            else
            {
                auto it2 = s2.find(A[i]);
                if(it2!=s2.end())
                {
                    tot++;
                    s2.erase(it2);
                }
                else s1.insert(A[i]);
                auto it1 = s1.find(B[i]);
                if(it1!=s1.end())
                {
                    tot++;
                    s1.erase(it1);
                }
                else s2.insert(B[i]);
            }
            res.push_back(tot);
        }
        return res;
    }
};