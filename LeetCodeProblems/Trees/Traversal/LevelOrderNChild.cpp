#include <vector>
#include "Node.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        traverse(root,1);
        return solutions;
    }
private:
    void traverse(Node* node, int level)
    {
        if(node!=nullptr)
        {
            if(solutions.size()<level) solutions.push_back({node->val});
            else solutions[level-1].push_back(node->val);
            for(int i=0;i<node->children.size();i++) traverse(node->children[i],level+1);
        }
    }

    vector<vector<int>> solutions;
};