using namespace std;

class Solution {
public:
    long long kMirror(int k, int n) {
        long long res = 0;
        int col = 1;
        int cur = 1;
        while(n>0)
        {
            long long val = generateNum(cur, col);
            if(isSimmetric(val,k))
            {
                n--;
                res+=val;
            }
            cur++;
            if(cur>=pow(10,((col-1)/2)+1))
            {
                col++;
                cur=pow(10,(col-1)/2);
            }
        }
        return res;
    }
private:
    long long generateNum(long long val, int col)
    {
        int val2 = 0;
        int temp = val;
        while(temp>0)
        {
            val2*=10;
            val2+=temp%10;
            temp/=10;
        }
        if(col%2==1) val/=10;
        val*=pow(10,((col-1)/2)+1);
        val+=val2;
        return val;
    }
    
    bool isSimmetric(long long num, int base)
    {
        string s;
        while(num>0)
        {
            s.push_back(num%base);
            num/=base;
        }
        int sz = s.size();
        for(int i=0;i<sz/2;i++)
        {
            if(s[i]!=s[sz-1-i]) return false;
        }
        return true;
    }
};