#include <vector>
#include "Node.cpp"
using namespace std;

class Solution {
public:
    vector<int> preorder(Node* root) {
        traverse(root);
        return result;
    }
private:
    void traverse(Node* node)
    {
        if(node!=nullptr)
        {
            result.push_back(node->val);
            for(int i=0;i<node->children.size();i++)
                traverse(node->children[i]);
        }
    }
    
    vector<int> result;
};