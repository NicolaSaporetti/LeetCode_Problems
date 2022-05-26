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

class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        heigthMap.push_back(root);
        while(root->left!=nullptr)
        {
            root=root->left;
            heigthMap.push_back(root);
        }
    }

    void searchNext()
    {
        if(heigthMap.size()==1)
        {
            heigthMap.pop_back();
        }
        if(heigthMap.size()>1)
        {
            if((*heigthMap[heigthMap.size()-2]).left==heigthMap[heigthMap.size()-1])
            {
                heigthMap.pop_back();
            }
            else{
                heigthMap.pop_back();
                searchNext();
            }
        }
    }
    
    int next() {
        int val=0;
        if(heigthMap.size()==0) val = -1;
        else{
            TreeNode* current = heigthMap[heigthMap.size()-1];
            if(current->left==nullptr &&
            current->right==nullptr)
            {
                val=current->val;
                searchNext();
            }
            else{
                val=current->val;
                if(current->right!=nullptr)
                {
                    current=current->right;
                    heigthMap.push_back(current);
                    while(current->left!=nullptr)
                    {
                        current=current->left;
                        heigthMap.push_back(current);
                    }
                }
                else
                {
                    searchNext(); 
                }
            }
        }
        return val;
    }
    
    bool hasNext() {
        if(heigthMap.size()==0) return false;
        else return true;
    }
    vector<TreeNode*> heigthMap;
};

int main()
{
    TreeNode* tree = new TreeNode();
    BSTIterator* obj = new BSTIterator(tree);
    int param_1 = obj->next();
    bool param_2 = obj->hasNext();
}