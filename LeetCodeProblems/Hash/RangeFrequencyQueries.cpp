#include <vector>
#include <map>
using namespace std;

class RangeFreqQuery {
public:
    RangeFreqQuery(vector<int>& arr) {
        for(int i=0;i<arr.size();i++) m[arr[i]].push_back(i);
    }
    
    int query(int left, int right, int value) {
        int l=lower_bound(m[value].begin(),m[value].end(),left)-m[value].begin();
        int r=lower_bound(m[value].begin(),m[value].end(),right)-m[value].begin();
        if(l>=m[value].size() || m[value][l]>right) return 0;
        if(r>=m[value].size() || m[value][r]>right) r--;
        return r-l+1;
    }
    map<int,vector<int>> m;
};