using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int res=0;
        bool f=true;
        while(f)
        {
            f=false;
            for(int i=0;i<s.size()-1;i++)
            {
                if(s[i]=='0' and s[i+1]=='1')
                {
                    f=true;
                    swap(s[i],s[i+1]);
                    i++;
                }
            }
            if(f)res++;
        }
        return res;
    }
};