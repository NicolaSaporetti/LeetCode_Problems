#include <vector>
using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for(int i=1;i<=n;i++)
        {
            int t = i*i;
            num.clear();
            while(t>0)
            {
                num.push_back(t%10);
                t/=10;
            }
            reverse(begin(num),end(num));
            if(decompose(0,i))
            {
                res+=(i*i);
            }
        }
        return res;
    }
private:
    bool decompose(int pos, int left)
    {
        if(left<0) return false;
        if(pos>=num.size())
        {
            return (left==0);
        }
        else
        {
            int t = 0;
            bool res = false;
            for(int i=pos;i<num.size() && !res;i++)
            {
                t*=10;
                t+=num[i];
                res |=decompose(i+1,left-t);
            }
            return res;
        }
    }
        
    vector<int> num;
};