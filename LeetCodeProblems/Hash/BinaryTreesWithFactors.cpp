#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        int mod = pow(10,9) + 7;
        int res = 0;
        sort(arr.begin(), arr.end());
        unordered_map <int, long> rootWithCount;
        for(int i = 0; i < arr.size(); i++){
            long count = 1;
            for(auto& [k,v] : rootWithCount){
                if(arr[i]%k==0 && rootWithCount.count(arr[i]/k)>0) count += v * rootWithCount[arr[i] / k];
            }
            rootWithCount[arr[i]] = count;
            res = (res + rootWithCount[arr[i]]) % mod;
        }
        return res;
    }
}