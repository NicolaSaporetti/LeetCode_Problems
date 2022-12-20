#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        rz = matrix.size();
        cz = matrix[0].size();
        int maxi = INT_MIN;
        
        for(int start_row = 0; start_row < rz; start_row++)
        {
            vector<int> col_array(cz, 0);
            for(int end_row = start_row; end_row < rz; end_row++)
            {
                for(int col = 0; col < cz; col++)
                {
                    col_array[col] += matrix[end_row][col];
                }
                int curr_max = find_max(col_array, k);
                maxi = max(maxi, curr_max);
            }
        }
        return maxi;
    }
    
private:
    int find_max(vector<int>& arr, int k)
    {
        int maxi = INT_MIN;
        int curr_sum = 0;
        set<int> s;
        s.insert(0);
        
        for(int i = 0; i < cz; i++)
        {            
            curr_sum += arr[i];
            auto it = s.lower_bound(curr_sum - k);
            if(it != s.end())
            {
                maxi = max(maxi, curr_sum - *it);
            }            
            s.insert(curr_sum);
        }
        
        return maxi;
    }
    
    int rz;
    int cz; 
};