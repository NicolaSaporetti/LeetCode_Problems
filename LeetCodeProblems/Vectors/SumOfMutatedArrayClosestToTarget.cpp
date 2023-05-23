#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int l = 0, r = arr[arr.size() - 1];
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            int diff = getDiff(arr, target, mid);
            if (diff >= 0) r = mid;
            else l = mid;
        }
        if (abs(getDiff(arr, target, l)) <= abs(getDiff(arr, target, r))) return l;
        else return r;
    }

    int getDiff(vector<int>& arr, int target, int value) {
        int diff;
        if (arr[0] >= value) {
            diff = value * arr.size() - target;
        } else if (arr[arr.size() - 1] <= value) {
            diff = std::accumulate(arr.begin(), arr.end(), 0) - target;
        } else {
            int sum = 0;
            for (int i = 0; i < arr.size() - 1; i++) {
                sum = sum + arr[i];
                if (arr[i] <= value && arr[i + 1] >= value) {
                    diff = sum + (arr.size() - i - 1) * value - target;
                    break;
                }
            }
        }
        return diff;
    }
};