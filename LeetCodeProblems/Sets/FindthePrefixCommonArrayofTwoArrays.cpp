#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> r;
        unordered_set<int> s1;
        unordered_set<int> s2;
        int c = 0;
        for(int i=0;i<A.size();i++)
        {
            if(A[i]==B[i]) c++;
            else
            {
                if(s2.count(A[i]))
                {
                    s2.erase(A[i]);
                    c++;
                }
                else s1.insert(A[i]);
                if(s1.count(B[i]))
                {
                    s1.erase(B[i]);
                    c++;
                }
                else s2.insert(B[i]);
            }
            r.push_back(c);
        }
        return r;
    }
};