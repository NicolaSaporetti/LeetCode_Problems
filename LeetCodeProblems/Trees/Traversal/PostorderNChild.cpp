#include <vector>
#include "Node.cpp"
using namespace std;

class Solution {
public:
    vector<int> postorder(Node* root) {
        traverse(root);
        return result;
    }
private:
    void traverse(Node* node)
    {
        if(node!=nullptr)
        {
            for(int i=0;i<node->children.size();i++) traverse(node->children[i]);
            result.push_back(node->val);
        }
    }
    vector<int> result;
};