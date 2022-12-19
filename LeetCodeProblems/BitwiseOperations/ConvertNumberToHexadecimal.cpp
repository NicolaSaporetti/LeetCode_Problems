using namespace std;

class Solution {
public:
    string toHex(int num) {
        string res;
        long long mask = 15;
        long long mask2 = 1;
        for(int i=0;i<8;i++)
        {
            int left = (num&(mask))/mask2;
            if(left<10) res+=(left+'0');
            else res+=(left-10+'a');
            mask*=16;
            mask2*=16;
        }
        while(res.size()>1 && res.back()=='0') res.pop_back();
        reverse(res.begin(),res.end());
        return res;
    }
};