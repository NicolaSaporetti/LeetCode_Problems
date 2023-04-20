#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<string> s;
        for(auto& e : nums) s.insert(e);
        int n = nums.size();
        for(int i=(1<<n)-1;i>=0;i--)
        {
            string t = computeRes(i,n);
            if(s.count(t)==0) return t;
        }
        return "";
    }
private:
    string computeRes(int num,int n)
    {
        string res;
        while(num>0)
        {
            res.push_back(num%2+'0');
            num/=2;
        }
        while(res.size()<n) res.push_back('0');
        reverse(begin(res),end(res));
        return res;
    }
};