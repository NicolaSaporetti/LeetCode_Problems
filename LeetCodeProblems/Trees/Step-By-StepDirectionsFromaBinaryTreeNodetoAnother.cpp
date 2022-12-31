#include <vector>
using namespace std;

class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<int> p1;
        string res;
        found = false;
        computePath(startValue, root, p1);
        vector<int> p2;
        found = false;
        computePath(destValue, root, p2);
        int level=0;
        for(int i=0;i<p1.size() && i<p2.size();i++)
        {
            level=i;
            if(p1[i]!=p2[i])
            {
                level--;
                break;
            }
        }
        for(int i=level;i<p1.size()-1;i++) res+='U';
        for(int i=1;i<p2.size();i++)
        {
            if(root->left!=nullptr && root->left->val==p2[i])
            {
                root=root->left;
                if(i>level) res+='L';
            }
            else
            {
                root=root->right;
                if(i>level) res+='R';
            }
        }
        return res;
    }
    
private:
    void computePath(int value, TreeNode* root, vector<int>& p)
    {
        if(root!=nullptr && !found)
        {
            p.push_back(root->val);
            if(root->val==value) found = true;
            if(!found) computePath(value, root->left,p);
            if(!found) computePath(value, root->right,p);
            if(!found) p.pop_back();
        }
    }
    
    bool found;
};