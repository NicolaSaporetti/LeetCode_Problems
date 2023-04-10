#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        visit(node);
        composeNodes();
        return newNodes[1];
    }

private:
    void visit(Node* node)
    {
        if(node==nullptr) return;
        newNodes[node->val] = new Node(node->val);
        for(auto& n : node->neighbors)
        {
            adj[node->val].push_back(n->val);
            if(newNodes.count(n->val)<=0) visit(n);
        }
    }

    void composeNodes()
    {
        for(auto& [key, node] : newNodes)
            for(auto n : adj[node->val]) newNodes[key]->neighbors.push_back(newNodes[n]);
    }

    unordered_map<int,Node*> newNodes;
    unordered_map<int,vector<int>> adj;
};