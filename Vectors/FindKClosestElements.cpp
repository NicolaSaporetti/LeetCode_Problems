class Solution {
private:
    vector<int> result;
    int setFirstIndex(vector<int>& arr, int x)
    {
        int Index = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
        if(Index==arr.size()) Index = arr.size()-1;
        else if(Index>0 && (abs(arr[Index-1]-x) <= abs(arr[Index]-x))) Index--;
        return Index;
    }
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int rightIndex = setFirstIndex(arr , x);
        int leftIndex = rightIndex;
        for(int i=1;i<k;i++)
        {
            if(leftIndex>0 && rightIndex<arr.size()-1)
            {
                if(abs(arr[leftIndex-1]-x) <= abs(arr[rightIndex+1]-x))
                {
                    leftIndex--;
                }
                else
                {
                    rightIndex++;
                }
            }
            else if(leftIndex==0)
            {
                rightIndex++;
            }
            else
            {
                leftIndex--;
            }
        }
        for(int i=leftIndex;i<=rightIndex;i++)
        {
            result.push_back(arr[i]);
        }
        return result;
    }
};