#include <vector>
using namespace std;

class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.length(), m = stamp.length();
        vector<int> ans;
        string str ; 
        bool foundMatch = true;
        
        while(foundMatch){ 
            foundMatch = false;
            for(int i=0;i<n-m+1;i++){
                str = target.substr(i,m);
                if(all_of(begin(target),end(target),[](char elem){return elem=='?';})) continue; 
                if(match(stamp,str)){
                    foundMatch = true;
                    ans.push_back(i);
                    for(int j=0;j<m;j++) target[i+j] = '?'; 
                }
            }
        }
        if(!all_of(begin(target),end(target),[](char elem){return elem=='?';}) || ans.size()>10*n)  ans.clear();        
        reverse(ans.begin(),ans.end());
        return ans;
    }
private:
    bool match(string& stamp,string& res){
        for(int i=0;i<stamp.length();i++)
            if(stamp[i]!=res[i] && res[i] != '?') 
                return false;
        return true;
    }
};