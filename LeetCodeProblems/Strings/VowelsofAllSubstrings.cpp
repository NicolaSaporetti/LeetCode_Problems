using namespace std;

class Solution {
public:
    long long countVowels(string s) {
        long long sz = s.size();
        long long res = 0;
        for(long long i=0;i<sz;i++) if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') res+=(i+1)*(sz-i);
        return res;
    }
};