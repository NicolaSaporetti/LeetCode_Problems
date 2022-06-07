class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int indexl = 0;
        int indexR = 0;
        int leftSide = 0;
        int rightSide = arr.size()-1;
        do
        {
            indexl=(leftSide+rightSide)/2;
            indexR=(leftSide+rightSide)/2+1;
            if(arr[indexl]>arr[indexR]) rightSide=indexR;
            else leftSide=indexl;
        } while (leftSide+2<rightSide);
        return (arr[indexl]>arr[indexR])? indexl : indexR;
    }
};