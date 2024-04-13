using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        string res;
        for(int i=0;i<num.size();i++)
        {
            while(k>0 && !res.empty() && res.back()>num[i])
            {
                res.pop_back();
                k--;
            }
            res.push_back(num[i]);
        }
        while(k>0 && res.size()>0)
        {
            res.pop_back();
            k--;
        }
        int n = 0;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]=='0') n++;
            else break;
        }
        res = res.substr(n,res.size()-n);
        return (res=="")? "0" : res;
    }
};