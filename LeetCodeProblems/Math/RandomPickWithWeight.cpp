#include <vector>
using namespace std;

class Solution {
public:
    Solution(vector<int>& w) {
        sz = w.size();
        cumulative.resize(w.size());
        cumulative[0] = w[0];
        for(int i=1;i<sz;i++)
        {
            cumulative[i]=cumulative[i-1]+w[i];
        }
    }
    
    int pickIndex() {
        int value = rand() % cumulative[sz-1];
        return lower_bound(cumulative.begin(),cumulative.end(),value+1)-cumulative.begin();
    }

private:
    vector<int> cumulative;
    int sz;
};