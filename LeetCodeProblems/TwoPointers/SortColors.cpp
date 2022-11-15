using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0; int mid = 0; int high = nums.size()-1;
        while(mid<=high){
            switch(nums[mid]){
                case 0:
                    swap(nums[mid++], nums[low++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }
    }
};