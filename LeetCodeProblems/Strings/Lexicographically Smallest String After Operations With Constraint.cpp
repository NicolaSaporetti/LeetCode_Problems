using namespace std;

class Solution {
public:
    string getSmallestString(string s, int k) {
        for(int i=0;i<s.size() && k>0;i++)
        {
            int toA = min(s[i]-'a','{'-s[i]);
            if(toA>k)
            {
                s[i]=min(s[i]+k,s[i]-k);
                k=0;
            }
            else
            {
                k-=toA;
                s[i]='a';
            }
        }
        return s;
    }
};