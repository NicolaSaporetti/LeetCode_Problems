#include <vector>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]++;
        return solve(root, 0, targetSum);
    }
    
private:
    int solve(TreeNode* root, long long currSum, int targetSum){
        if(root == NULL) return 0;      
        
        currSum += root->val;
        
        int res = 0;
        if(mp.find(currSum-targetSum) != mp.end()) res = mp[currSum-targetSum];
        
        mp[currSum]++;
        res += solve(root->left, currSum, targetSum);
        res += solve(root->right, currSum, targetSum);
        mp[currSum]--;
        
        return res;
    }
    
    unordered_map<long long,int> mp;
};