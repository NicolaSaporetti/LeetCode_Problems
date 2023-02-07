#include <vector>
using namespace std;

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        multiset<long long> m;
        long long tot = 0;
        for(auto& e : gifts) m.insert(e);
        for(int i=0;i<k;i++)
        {
            auto it = m.rbegin();
            long long left = sqrt(*it);
            m.insert(left);
            m.erase(std::next(it).base());
        }
        for(auto& e : m) tot+=e;
        return tot;
    }
};