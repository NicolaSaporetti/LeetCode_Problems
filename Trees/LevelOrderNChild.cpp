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
    vector<vector<int>> solutions;
    void traverse(Node* node, int level)
    {
        if(solutions.size()<level)
        {
            vector<int> newVector;
            newVector.push_back(node->val);
            solutions.push_back(newVector);
        }
        else
            solutions[level-1].push_back(node->val);
        for(int i=0;i<node->children.size();i++)
        {
            traverse(node->children[i],level+1);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root!=nullptr)
            traverse(root,1);
        return solutions;
    }
};

int main()
{
    Solution sol;
    return 0;
}