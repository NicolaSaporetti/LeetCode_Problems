#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        int ones = count_if(begin(s),end(s),[](char e){return e=='1';});
        int zeros = count_if(begin(s),end(s),[](char e){return e=='0';});
        if(abs(ones-zeros)>1) return -1;
        bool val = false;
        int res = 0;
        int sz = s.size();
        if(sz%2==0)
        {
            for(int i=0;i<sz;i++)
            {
                if((s[i]=='0' && !val) || (s[i]=='1' && val)) res++;
                val = !val;
            }
            return min((sz-res+1)/2,(res+1)/2);
        }
        else
        {
            if(ones>zeros) val = true;
            for(int i=0;i<sz;i++)
            {
                if((s[i]=='0' && !val) || (s[i]=='1' && val)) res++;
                val = !val;
            }
            return (sz-res)/2;
        }
    }
};