#include <iostream>
#include <vector>
#include "Node.cpp"
using namespace std;

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