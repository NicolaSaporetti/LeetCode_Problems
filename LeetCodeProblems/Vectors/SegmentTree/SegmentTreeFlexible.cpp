struct SegmentTreeNode {
    int val;
    int amount;
    int size;
    SegmentTreeNode *left;
    SegmentTreeNode *right;
    SegmentTreeNode(int x) : val(x), size(1), amount(1), left(nullptr), right(nullptr) {}
};

class SegmentTreeFlexible
{
public:
    SegmentTreeFlexible() : root(nullptr) {}
    
    int insert(int val)
    {
        if(root != nullptr) return traverse(root, val, 0);
        else
        {
            root = new SegmentTreeNode(val);
            return 0;
        }
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
                cout<<t1->val<<" Amount: "<<t1->amount<<" Size: "<<t1->size<<endl;
                if(t1->left!=nullptr) temp.push(t1->left);
                if(t1->right!=nullptr) temp.push(t1->right);
            }
            cout<<endl;
        }
    }

private:
    int traverse(SegmentTreeNode* root, int val, int elementOnRight)
    {
        int res = elementOnRight;
        if(root->val>val)
        {
            if(root->left!=nullptr)  res = traverse(root->left,val,elementOnRight);
            else
            {
                root->left = new SegmentTreeNode(val);
            }
        }
        else if(root->val<val)
        {
            if(root->right!=nullptr) res = traverse(root->right,val,elementOnRight+root->size-root->right->size);
            else
            {
                res+=root->size;
                root->right = new SegmentTreeNode(val);
            }
        }
        else
        {
            root->amount++;
            if(root->left!=nullptr) res+=root->left->size;
        }
        root->size++;
        return res;
    }

    SegmentTreeNode* root;
};