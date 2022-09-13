#include <vector>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int start=0,end=citations.size()-1,ans=0;
        while (start<=end) {
            int mid=start+(end-start)/2;
            if (citations[mid]>=citations.size()-mid) {
                ans=citations.size()-mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};