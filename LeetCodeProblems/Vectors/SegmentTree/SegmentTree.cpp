#include <vector>
#include <queue>
using namespace std;

struct SegmentTreeNode {
    int val;
    int hi;
    int lo;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int x, int num) : val(x), hi(num), lo(num), left(nullptr), right(nullptr) {}
    SegmentTreeNode(int x, int hi, int lo, SegmentTreeNode *left, SegmentTreeNode *right) : val(x), hi(hi), lo(lo), left(left), right(right) {}
};

class SegmentTree
{
public:
    SegmentTree(vector<int>& arr)
    {
        queue<SegmentTreeNode*> temp;
        for(int i=0;i<arr.size();i++)
        {
            SegmentTreeNode* tn = new SegmentTreeNode(arr[i],i);
            temp.push(tn);
        }
        while(temp.size()>1)
        {
            int num = temp.size();
            for(int i=0;i<num/2;i++)
            {
                SegmentTreeNode* t1 = temp.front();
                temp.pop();
                SegmentTreeNode* t2 = temp.front();
                temp.pop();
                SegmentTreeNode* n = new SegmentTreeNode(t1->val+t2->val,t2->hi,t1->lo,t1,t2);
                temp.push(n);
            }
            if(num%2==1)
            {
                temp.push(temp.front());
                temp.pop();
            }
        }
        root = temp.front();
        temp.pop();
    }

    void update(int diff, int el)
    {
        updateNode(root, diff, el);
    }

    int sumRange(int lo, int hi)
    {
        return sumRangeNodes(root, lo, hi);
    }
    
    void printTree()
    {
        queue<SegmentTreeNode*> temp;
        temp.push(root);
        while(!temp.empty())
        {
            int num = temp.size();
            for(int i=0;i<num;i++)
            {
                SegmentTreeNode* t1 = temp.front();
                temp.pop();
                cout<<t1->val<<" lo: "<<t1->lo<<" hi: "<<t1->hi<<endl;
                if(t1->left!=nullptr) temp.push(t1->left);
                if(t1->right!=nullptr) temp.push(t1->right);
            }
            cout<<endl;
        }
    }

private:
    void updateNode(SegmentTreeNode* cur, int diff, int el)
    {
        if(cur->lo<=el && cur->hi>=el)
        {
            cur->val-=diff;
            if(cur->lo == cur->hi) return;
            else if(cur->left->hi<el) {
                updateNode(cur->right, diff, el);
            }
            else {
                updateNode(cur->left, diff, el);
            }
        }
    }

    int sumRangeNodes(SegmentTreeNode* cur, int lo, int hi)
    {
        int tot = 0;
        if(isRangeSumGreaterOrEqualCurrentRange(cur,lo,hi)) tot = cur->val;
        else if(isRangeSumOutsideCurrentRange(cur,lo,hi)) tot = 0;
        else
        {
            tot+=sumRangeNodes(cur->left,lo,hi)+sumRangeNodes(cur->right,lo,hi);
        }
        return tot;
    }
    
    inline bool isRangeSumGreaterOrEqualCurrentRange(SegmentTreeNode* cur, int lo, int hi) {
        return (cur->lo>=lo && cur->hi<=hi);
    }
    
    inline bool isRangeSumOutsideCurrentRange(SegmentTreeNode* cur, int lo, int hi) {
        return (cur->hi<lo || cur->lo>hi);
    }

    SegmentTreeNode* root;
};