#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        vector<int> disL(n+1,0);
        vector<int> disR(n+1,0);
        if (x > y) swap(x, y);

        // Precompute distances and their frequencies for houses in the range (x, y)
        for (int i = x + 1; i < y; i++) {
            int tmpL = min(i - x, y - i + 1);
            int tmpR = min(i - x + 1, y - i);
            disL[tmpL]++, disR[tmpR]++;
        }
        vector<long long> ans(n, 0);

        int line = n - max(y - x - 1, 0);
        int circ = y - x + 1;
        int l1 = -(x - 2), l2 = -(n - y - 1);
        int sumL = 0, sumR = 0;

        for (int k = 1; k <= n; k++) {
            ans[k - 1] += max(0, line - k);

            if (2 * k < circ) ans[k - 1] += circ;
            else if (2 * k == circ) ans[k - 1] += circ / 2;

            // Case 3: One endpoint is in (x, y), while the other is in [1, x) U (y, n]
            ans[k - 1] += sumL + sumR;

            // Update sumL and sumR by removing outdated distances
            if (l1 >= 0) sumL -= disL[l1];
            if (l2 >= 0) sumR -= disR[l2];

            // Update indices for distances
            l1++, l2++;

            // Add new distances to sumL and sumR
            sumL += disL[k];
            sumR += disR[k];
        }

        // Subtract 1 from the result for overlapping pair when x != y
        if (x != y) ans[0]--;

        for (auto &i : ans) i *= 2;
        return ans;
    }
};