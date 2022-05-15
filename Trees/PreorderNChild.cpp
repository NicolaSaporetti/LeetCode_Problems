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
        result.push_back(node->val);
        for(int i=0;i<node->children.size();i++)
            traverse(node->children[i]);
    }
public:
    vector<int> preorder(Node* root) {
        if(root!=nullptr)
            traverse(root);
        return result;
    }
};

int main()
{
    Solution solution;
}