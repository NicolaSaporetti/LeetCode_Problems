using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int sz = version1.size();
        int sz2 = version2.size();
        int i = 0;
        int j = 0;
        while(i<sz || j<sz2)
        {
            long long v1 = 0;
            long long v2 = 0;
            while(i<sz && version1[i]!='.')
            {
                v1*=10;
                v1+=(version1[i]-'0');
                i++;
            }
            while(j<sz2 && version2[j]!='.')
            {
                v2*=10;
                v2+=(version2[j]-'0');
                j++;
            }
            if(i<sz && version1[i]=='.') i++;
            if(j<sz2 && version2[j]=='.') j++;
            if(v1<v2) return -1;
            else if(v1>v2) return 1;
        }
        return 0;
    }
};