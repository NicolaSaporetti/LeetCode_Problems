#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(auto& e : nums2) m[e]++;
        num = nums1;
        num2 = nums2;
    }
    
    void add(int index, int val) {
        m[num2[index]]--;
        if(m[num2[index]]==0) m.erase(num2[index]);
        num2[index]+=val;
        m[num2[index]]++;
    }
    
    int count(int tot) {
        int res = 0;
        for(int i=0;i<num.size();i++)
        {
            res+=m[tot-num[i]];
        }
        return res;
    }
    
    vector<int> num;
    vector<int> num2;
    unordered_map<int,int> m;
};