#include <vector>
#include <queue>
#include "TreeNode.cpp"
using namespace std;

class Codec {
public:

    string serialize(TreeNode* root) {
        if(root==NULL) return "-1001";
        string ans="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            
            if(x==nullptr) ans+=" "+to_string(-1001);
            else
            {
                ans+=" "+to_string(x->val);
                q.push(x->left);
                q.push(x->right);
            }
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        if(data=="-1001") return NULL;
        vector<int>res = simple_tokenizer(data);
        int i=1;
        queue<TreeNode *>q;
        TreeNode *root=new TreeNode(res[0]);
        q.push(root);
        while(!q.empty()){
            auto x=q.front();
            if(res[i]!=-1001){
                x->left=new TreeNode(res[i]);
                q.push(x->left);
            }
            i++;
            if(res[i]!=-1001){
                x->right=new TreeNode(res[i]);
                q.push(x->right);
            }
            i++;
            q.pop();
        }
        return root;
    }
    
    vector<int> simple_tokenizer(string s)
    {
        stringstream ss(s);
        string word;
        vector<int> res;
        while (ss >> word) res.push_back((stoi(word)));
        return res;
    }
};