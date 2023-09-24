#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        for(auto& w : words)
        {
            m[w.size()].insert(w);
            chainLenght[w]=1;
        }
        for(int i=2;i<=16;i++)
        {
            for(auto& suc : m[i])
            {
                for(auto& pred : m[i-1])
                {
                    if(isPredecessor(suc,pred)) chainLenght[suc]=max(chainLenght[suc],chainLenght[pred]+1);
                }
            }
        }
        int result = 0;
        for(auto& [key,chain] : chainLenght) result = max(result, chain);
        return result;
    }
private:
    bool isPredecessor(const string& succe, const string& pred)
    {
        bool insertionFound = false;
        int sz = pred.size();
        int j=0;
        for(int i=0;i<sz+1 && j<sz;i++) if(succe[i]==pred[j]) j++;
        return j==sz;
    }

    unordered_map<int,unordered_set<string>> m;
    unordered_map<string,int> chainLenght;
};