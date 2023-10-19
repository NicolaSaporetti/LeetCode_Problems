#include <vector>
using namespace std;

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        tg = target;
        int left = mountainArr.get(0);
        int right = mountainArr.get(mountainArr.length()-1);
        computePeak(mountainArr, mountainArr.length());
        if(left>target && right>target) return -1;
        else return compute(0,mountainArr.length()-1,left,right,mountainArr);
    }
private:
    void computePeak(MountainArray & arr, int n)
    {
        int start=0,end=n-1;
        peak=-1;
        while(start<end)
        {
            int mid=start + (end-start)/2;
            if(arr.get(mid+1)>arr.get(mid))
            {
                start=mid+1;
                peak=mid+1;
            }
            else end=mid;
        }
    }
    int compute(int pleft, int pright, int left, int right, MountainArray &mnt)
    {
        if(pleft+1>=pright)
        {
            if(left==tg) return pleft;
            else if(right==tg) return pright;
            else return -1;
        }
        else
        {
            int pmid = pleft+(pright-pleft)/2;
            int mid = mnt.get(pmid);
            if((left<=tg && mid>=tg) || (left>=tg && mid<=tg) || (peak>=pleft && peak<=pmid))
            {
                int p = compute(pleft,pmid,left,mid,mnt);
                if(p!=-1) return p; 
            }
            if((right<=tg && mid>=tg) || (right>=tg && mid<=tg) || (peak>=pmid && peak<=pright))
            {
                int p = compute(pmid,pright,mid,right,mnt);
                if(p!=-1) return p; 
            }
            return -1;
        }
    }

    int tg;
    int peak;
};