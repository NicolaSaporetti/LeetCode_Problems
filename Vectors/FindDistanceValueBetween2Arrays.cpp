#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = arr1.size();
        bool exit = false;
        for(int i=0;i<arr1.size();i++)
        {
            exit = false;
            for(int j=0;j<arr2.size() && !exit;j++)
            {
                if(abs(arr1[i]-arr2[j])<=d)
                {
                    count--;
                    exit = true;
                }
            }
        }
        return count;
    }
};