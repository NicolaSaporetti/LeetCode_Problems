#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
      unordered_map<string, int> masks;
      unordered_map<string, vector<string>> groups;
      long long ans = 0;
      int cnt[26][26] = {};
      
      for (int i=0;i<ideas.size();i++) {
        string suff = ideas[i].substr(1);
        groups[suff].push_back(ideas[i]);
        masks[suff] |= 1 << (ideas[i][0] - 'a');
      }
      
      for (auto it=groups.begin();it!=groups.end();it++) {
        int curr_mask = masks[it->first];
        for (int j=0;j<it->second.size();j++) {
          for (int i = 0; i < 26; i++) {
            if (curr_mask & (1 << i)) continue;
            ans += cnt[i][it->second[j][0] - 'a'];
          }
        }
        
        for (int j=0;j<it->second.size();j++) {
          for (int i = 0; i < 26; i++) {
            if (curr_mask & (1 << i)) continue;
            cnt[it->second[j][0] - 'a'][i]++;
          }
        }
      }
      
      return 2 * ans;
    }
};