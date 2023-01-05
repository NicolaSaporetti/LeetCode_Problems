#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int time=tasks.size();        
        vector<int> counter(26,0);
        for(auto& task : tasks) counter[task-'A']++;
        int maxi=*max_element(counter.begin(),counter.end());
        int cntMaxi=0;
        
        for(int i=0; i<26; i++){
            if(counter[i]==maxi){
                cntMaxi++;
            }
        }

        int ans=maxi+(n*(maxi-1));
        if(cntMaxi>1) ans+=(cntMaxi-1);
        
        return max(time,ans);
    }
};