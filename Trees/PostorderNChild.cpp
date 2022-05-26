#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
private:
    vector<int> result;
    void traverse(Node* node)
    {
        for(int i=0;i<node->children.size();i++)
        {
            traverse(node->children[i]);
        }
        result.push_back(node->val);
    }
public:
    vector<int> postorder(Node* root) {
        if(root!=nullptr)
            traverse(root);
        return result;
    }
};

int main()
{
    Solution solution;
    return 0;
}