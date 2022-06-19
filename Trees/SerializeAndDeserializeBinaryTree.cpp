#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Codec {
public:

    string serialize(TreeNode* root) {
        if(root==NULL)return "-1001";
        string ans="";
        queue<TreeNode *>q;
        q.push(root);
        while(!q.empty()){
            auto x=q.front();
            
            ans+=" "+to_string(x->val);
            if(x->val==-1001){
                q.pop();
                continue;
            }
            if(x->left){
                q.push(x->left);
                
            }
            else{
                q.push(new TreeNode(-1001));
            }
            if(x->right){
                q.push(x->right);
            }
            else{
                q.push(new TreeNode(-1001));
            }
            q.pop();
        }
        return ans;
    }

    TreeNode* deserialize(string data) {
        cout<<data;
        if(data=="-1001")return NULL;
        vector<int>res=simple_tokenizer(data);
        int i=1;
        queue<TreeNode *>q;
        TreeNode *root=new TreeNode(res[0]);
        q.push(root);
        while(!q.empty() && i<res.size()){
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
        vector<int>res;
        while (ss >> word) {
            
            res.push_back((stoi(word)));
           
        }
        return res;
    }
};