#include <queue>
#include <vector>
#include "TreeNode.cpp"
using namespace std;

class LockingTree {
public:
    LockingTree(vector<int>& parent) : pred(parent){
        int sz = parent.size();
        childs.resize(sz);
        locked.assign(sz,{0,false});
        for(int i=0;i<sz;i++)
        {
            if(parent[i]!=-1) childs[parent[i]].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if(!locked[num].second)
        {
            locked[num] = {user,true};
            return true;
        }
        else return false;
    }
    
    bool unlock(int num, int user) {
        if(locked[num].second && locked[num].first==user)
        {
            locked[num] = {0,false};
            return true;
        }
        else return false;
        
    }
    
    bool upgrade(int num, int user) {
        if(!locked[num].second)
        {
            int node = num;
            while(pred[node]!=-1)
            {
                node = pred[node];
                if(locked[node].second==true) return false;
            }
            traverse(num);
            if(lockedDescendant.empty()) return false;
            while(!lockedDescendant.empty())
            {
                locked[lockedDescendant.front()]={0,false};
                lockedDescendant.pop();
            }
            locked[num] = {user,true};
            return true;
        }
        return false;
        
    }
private:
    void traverse(int node)
    {
        for(int i=0;i<childs[node].size();i++)
        {
            traverse(childs[node][i]);
        }
        if(locked[node].second) lockedDescendant.push(node);
    }
    
    
    vector<vector<int>> childs;
    vector<int> pred;
    vector<pair<int,bool>> locked;
    queue<int> lockedDescendant;
};