#include <vector>
using namespace std;

class Solution {
public:
    int punishmentNumber(int n) {
        int res = 0;
        for(int i=1;i<=n;i++)
        {
            int t = i*i;
            vector<int> num;
            while(t>0)
            {
                num.push_back(t%10);
                t/=10;
            }
            if(decompose(num.size()-1,0,i,num)) res+=(i*i);
        }
        return res;
    }
private:
    bool decompose(int pos, int tot, int left, vector<int>& num)
    {
        if(left<0) return false;
        if(pos<0) return (left==0 && tot==0);
        else
        {
            tot = (tot*10+num[pos]);
            return decompose(pos-1,tot,left,num) | decompose(pos-1,0,left-tot,num);
        }
    }
        
    vector<int> num;
    int val;
};