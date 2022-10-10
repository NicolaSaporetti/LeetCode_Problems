#include <vector>
using namespace std;

class Solution {
public:
    int countDaysTogether(string sa1, string sa2, string sb1, string sb2) {
        int a1 = td(sa1), a2 = td(sa2), b1 = td(sb1), b2 = td(sb2);
        int ans = 0;
        int da = max(a1,b1);
        int dd = min(a2,b2);
        if(da<=dd) ans = dd-da+1;
        return ans;
    }
private:
    int td(string s) {
        int tot = 0;
        int m = s[1] - '0' + 10*(s[0] - '0');
        int d = s[4] - '0' + 10*(s[3] - '0');
        for(int i=1;i<m;i++) tot+=md[i-1];
        return tot+d;
    }
    
    vector<int> md = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};