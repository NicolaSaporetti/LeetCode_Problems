using namespace std;

class Solution {
public:
    string maxValue(string n, int x) {
        string res;
        bool used = false;
        if(n[0]=='-')
        {
            res.push_back(n[0]);
            for(int i=1;i<n.size();)
            {
                if(!used && n[i]-'0'>x)
                {
                    res.push_back(x+'0');
                    used = true;
                }
                else res.push_back(n[i++]);
            }
            if(!used) res.push_back(x+'0');
        }
        else
        {
            for(int i=0;i<n.size();)
            {
                if(!used && n[i]-'0'<x)
                {
                    res.push_back(x+'0');
                    used = true;
                }
                else res.push_back(n[i++]);
            }
            if(!used) res.push_back(x+'0');
        }
        return res;
    }
};