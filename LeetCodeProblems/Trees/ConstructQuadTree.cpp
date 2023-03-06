#include <vector>
using namespace std;

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int sz = grid.size();
        return computeQuadTree(grid,0,0,sz);
    }
private:
    Node* computeQuadTree(vector<vector<int>>& grid, int r, int c, int sz)
    {
        if(sz==1)
        {
            Node* node = new Node(grid[r][c],true);
            return node;
        }
        else
        {
            Node* node = new Node();
            node->topLeft = computeQuadTree(grid,r,c,sz/2);
            node->topRight = computeQuadTree(grid,r,c+sz/2,sz/2);
            node->bottomLeft = computeQuadTree(grid,r+sz/2,c,sz/2);
            node->bottomRight = computeQuadTree(grid,r+sz/2,c+sz/2,sz/2);
            if((grid[r][c]==0 && grid[r][c+sz/2]==0 && grid[r+sz/2][c]==0 && grid[r+sz/2][c+sz/2]==0) ||
               (grid[r][c]==1 && grid[r][c+sz/2]==1 && grid[r+sz/2][c]==1 && grid[r+sz/2][c+sz/2]==1))
            {
                node->topLeft = nullptr;
                node->topRight = nullptr;
                node->bottomLeft = nullptr;
                node->bottomRight = nullptr;
                node->isLeaf = true;
                node->val = grid[r][c];
            }
            else grid[r][c]=2;
            return node;
        }
    }
};