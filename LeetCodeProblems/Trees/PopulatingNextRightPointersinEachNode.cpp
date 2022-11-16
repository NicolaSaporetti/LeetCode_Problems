#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            for(int i=0;i<sz;i++)
            {
                Node* elem = q.front();
                q.pop();
                if(elem==nullptr) continue;
                if(i!=sz-1) elem->next=q.front();
                q.push(elem->left);
                q.push(elem->right);
            }
        }
		return root;
	}
};