using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k==1)
        {
            string res=s;
            for(int i=1;i<s.size();i++)
            {
                string temp = s.substr(i,s.size()-i)+s.substr(0,i);
                if(res>temp) res = temp;
            }
            s = res;
        }
        else sort(s.begin(),s.end());
        return s;
    }
};