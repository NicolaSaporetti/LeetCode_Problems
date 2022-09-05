#include <vector>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> presum(n+1,0);
        for(auto x: shifts){
            if(x[2]==0){
                presum[x[0]]--;
                presum[x[1]+1]++;
            }
            else{
                presum[x[0]]++;;
                presum[x[1]+1]--;
            }            
        }
        
        for(int i = 1; i<presum.size();i++)
            presum[i]+=presum[i-1];        
        
        for(int i =0; i<n; i++)
        {
            s[i]= (((s[i]-'a'+presum[i])%26+26)%26)+'a';
        }
        
        return s;
    }
};