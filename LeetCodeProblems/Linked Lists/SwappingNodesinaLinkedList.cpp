#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        nodes = k;
        swapNode(head,k-1);
        return head;
    }
private:
    int swapNode(ListNode* node, int left_nodes)
    {
        if(node == nullptr) return nodes-1;
        if(left_nodes==0) nodeToSwap = node;
        int val = swapNode(node->next,left_nodes-1);
        if(val==0) swap(node->val,nodeToSwap->val);
        return val-1;

    }

    ListNode* nodeToSwap;
    int nodes;
};