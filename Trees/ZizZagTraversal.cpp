#include <iostream>
#include <vector>
#include <map>
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
	void updateSolutions(int level, int val)
	{
		if(solutions.size()==level)
		{
			vector<int> newVector;
			newVector.push_back(val);
			solutions.push_back(newVector);
		}
		else
		{
			solutions[level].push_back(val);
		}
	}
	void traverse(TreeNode* p, int level)
	{
		updateSolutions(level,p->val);
		if(p->left!=nullptr)
		{
			traverse(p->left,level+1);
		}
		if(p->right!=nullptr)
		{
			traverse(p->right,level+1);
		}
	}
    void applyZigZag()
    {
        int temp =0;
        for(int i=1;i<solutions.size();i+=2)
        {
            int sz = solutions[i].size();
            for(int j=0;j<sz/2;j++)
            {
                temp = solutions[i][j];
                solutions[i][j] = solutions[i][sz-1-j];
                solutions[i][sz-1-j] = temp;
            }
        }
    }
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if(root!=nullptr)
		{
			traverse(root, 0);
		}
        applyZigZag();
		return solutions;
	}
};

int main()
{
    Solution solution;
    return 0;
}