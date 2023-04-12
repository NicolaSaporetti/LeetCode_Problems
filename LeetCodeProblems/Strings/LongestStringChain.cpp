#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        for(auto& w : words) m[w.size()].insert(w);
        for(auto& w : words) chainLenght[w]=1;
        int result = 0;
        for(int i=1;i<=16;i++)
        {
            for(auto& suc : m[i])
            {
                for(auto& pred : m[i-1])
                {
                    if(isPredecessor(suc,pred)) chainLenght[suc]=max(chainLenght[suc],chainLenght[pred]+1);
                }
            }
        }
        for(auto& [key,chain] : chainLenght) result = max(result, chain);
        return result;
    }
private:
    bool isPredecessor(const string& succe, const string& pred)
    {
        int i=0;
        bool insertionFound = false;
        bool predecessorExist = true;
        while(i+insertionFound<succe.size())
        {
            if(succe[i+insertionFound]!=pred[i])
            {
                if(insertionFound)
                {
                    predecessorExist = false;
                    break;
                }
                else insertionFound = true;
            }
            else i++;
        }
        return predecessorExist;
    }

    unordered_map<int,unordered_set<string>> m;
    unordered_map<string,int> chainLenght;
};