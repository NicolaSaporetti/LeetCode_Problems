class Solution {
    unordered_set<int> myS;
    int mask;
    
    void createMask(int k)
    {
        for(int i=0;i<k;i++)
        {
            mask|=1<<i;
        }
    }
public:
    bool hasAllCodes(string s, int k) {
        bool res = false;
        if(s.size()>=k)
        {
            int value = 0;
            int i = 0;
            createMask(k);
            for(;i<k;i++)
            {
                value<<=1;
                if(s[i]=='1') value|=1;
            }
            myS.insert(value);
            for(;i<s.size();i++)
            {
                value<<=1;
                value&=mask;
                if(s[i]=='1') value|=1;
                myS.insert(value);
            }
            if(myS.size()==pow(2,k)) res = true;
        }
        return res;
    }
};