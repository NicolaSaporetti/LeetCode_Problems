#include <vector>
using namespace std;

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        vector<int> original(n,0);
        original[0]=0;
        for(int i=0;i<n-1;i++)
        {
            original[i+1]=derived[i]^original[i];
        }
        if(original[0]^original[n-1]==derived[n-1]) return true;
        original.assign(n,0);
        original[0]=1;
        for(int i=0;i<n-1;i++)
        {
            original[i+1]=derived[i]^original[i];
        }
        if(original[0]^original[n-1]==derived[n-1]) return true;
        return false;
    }
};