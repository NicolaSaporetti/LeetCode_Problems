#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) v[i] = {nums[i],i};
        count.assign(n,0);
        mergeSort(0,n-1,v);
        return count;
    }

private:
    void mergeSort(int l, int r,vector<pair<int,int>>& v)
    {
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(l,mid,v);
        mergeSort(mid+1,r,v);
        merge(l,mid,r,v);
    }

    void merge(int l, int mid, int r,vector<pair<int,int>>& v)
    {
        vector<pair<int,int>> temp(r-l+1);
        int i = l;
        int j= mid + 1;
        int pos = 0;
        int shift=0;
        while(i<mid+1 || j<=r)
        {
            if(j>r || (i<=mid && v[i].first<=v[j].first))
            {
                count[v[i].second] += shift;
                temp[pos++] = v[i++];
            }
            else{
                temp[pos++] = v[j++];
                shift++;
            }
        }
        
        for(int i=l;i<=r;i++) v[i] = temp[i-l];
    }

    vector<int> count;
};