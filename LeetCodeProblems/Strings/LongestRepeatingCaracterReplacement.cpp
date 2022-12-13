#include <vecotr>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> cnt(26, 0);
        int maxFreq = 0, winSize = 0;
        int ret = 0;
        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            cnt[s[r]-'A']++;
            maxFreq = *max_element(cnt.begin(), cnt.end());
            winSize = r - l + 1;
            while (winSize - maxFreq > k)
            {
                cnt[s[l]-'A']--;
                l++;
                maxFreq = *max_element(cnt.begin(), cnt.end());
                winSize = r - l + 1;
            }
            ret = max(winSize, ret);
        }
        return ret;
    }
};