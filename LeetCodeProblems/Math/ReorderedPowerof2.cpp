#include <vector>
using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(),s.end());
		
        vector<string> power;
        int p = 1;
        for(int i=0;i<30;i++){
            power.push_back(to_string(p));
            p*=2;
        }
        
        for(auto& e : power) sort(begin(e), end(e));
        
        for(int i=0;i<=30;i++){
            if(power[i] == s ) return true;
        }
        return false;
    }
};