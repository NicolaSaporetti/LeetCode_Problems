#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++)
        {
            int temp = arr[i];
            sum+=temp;
            for(int j=i+2;j<arr.size();j+=2)
            {
                temp+=arr[j-1];
                temp+=arr[j];
                sum+=temp;
            }
        }
        return sum;
    }
};