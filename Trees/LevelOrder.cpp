#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
	vector<vector<int>> solutions;
	void traverse(TreeNode* p, int level)
	{
		if(solutions.size()!=level)
		{
			solutions[level].push_back(p->val);
		}
		else
		{
			vector<int> newVector;
			newVector.push_back(p->val);
			solutions.push_back(newVector);
		}
		if(p->left!=nullptr)
		{
			traverse(p->left,level+1);
		}
		if(p->right!=nullptr)
		{
			traverse(p->right,level+1);
		}
	}
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if(root!=nullptr)
		{
			traverse(root, 0);
		}
		return solutions;
	}
};

int main()
{
    Solution sol;
    return 0;
}