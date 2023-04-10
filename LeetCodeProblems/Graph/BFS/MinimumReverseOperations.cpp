#include <unordered_set>
#include <set>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    inline pair<int, int> getRange(int n, int pivot, int k) {
        int l1 = max(0, pivot - k + 1);
        int r1 = l1 + k - 1;
		
        int r2 = min(n - 1, pivot + k - 1);
        int l2 = r2 - k + 1;
		
		int left = r1 - (pivot - l1);
        int right = l2 + (r2 - pivot);
        return {left, right};
    }
    
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> bans(banned.begin(), banned.end());
        vector<int> ans(n, -1);
        set<int> s[2];

        ans[p] = 0;
        for (int i = 0; i < n; i ++)
            if (i != p && bans.find(i) == bans.end())
                s[i & 1].insert(i);
        
        queue<int> q;
        q.push(p);
        while (!q.empty()) {
            int pivot = q.front();
            q.pop();
            auto range = getRange(n, pivot, k);

            int o = (k % 2 == 0) ? (1 - pivot & 1) : (pivot & 1);

            auto bg = s[o].lower_bound(range.first);
            auto ed = s[o].upper_bound(range.second);

            for (auto it = bg; it != ed; it ++) {
                ans[*it] = ans[pivot] + 1;
                q.push(*it);
            }
            s[o].erase(bg, ed);
        }

        return ans;
    }
};