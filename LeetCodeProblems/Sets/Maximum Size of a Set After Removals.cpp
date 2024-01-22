#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        set<int> s2;
        for(auto e : nums1) s1.insert(e);
        for(auto e : nums2) s2.insert(e);
        int over = 0;
        for(auto e : s1) if(s2.find(e)!=s2.end()) over++;
        int sz = nums1.size();
        if(s1.size()-over>=sz/2) return sz/2+min(sz/2,(int)s2.size());
        else if(s2.size()-over>=sz/2) return sz/2+min(sz/2,(int)s1.size());
        else return min((int)(s1.size()-over+s2.size()),(int)sz);
    }
};