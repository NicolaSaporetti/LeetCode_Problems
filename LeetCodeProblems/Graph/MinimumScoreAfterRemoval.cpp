#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
private:
    unordered_map<int,unordered_set<int>> adj;
    vector<vector<bool>> children;
public:
    int dfs(vector<int> &nums, int node, vector<bool> &vis){
        vis[node]=true;
        int res=nums[node];
        for(auto nei: adj[node]){
            if(vis[nei]==false){
                res=res^dfs(nums,nei,vis);
            }
        }
        nums[node]=res;
        return res;
    }
    
    void find_childrens(int node, vector<bool> &vis){
        vis[node]=true;
        for(auto nei: adj[node]){
            if(vis[nei]==false){
                find_childrens(nei,vis);
                children[node][nei]=true;
                for(int i=0;i<vis.size();i++)
                {
                    children[node][i]=children[node][i] | children[nei][i];
                }
            }
        }
    }
    
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n=edges.size();
        for(auto edge: edges){
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }
        int res=INT_MAX;
        vector<bool> vis(nums.size(),false);  
        int temp=dfs(nums,0,vis);
        children.assign(nums.size(),vector<bool>(nums.size(),false));
        vis.assign(nums.size(),false);
        find_childrens(0,vis);
        int score=INT_MAX;
        for(int i=0;i<edges.size()-1;i++)
        {
            for(int j=i+1;j<edges.size();j++)
            {
                int nodeA = (children[edges[i][0]][edges[i][1]])? edges[i][1] : edges[i][0];
                int nodeB = (children[edges[j][0]][edges[j][1]])? edges[j][1] : edges[j][0];
                int valueA = nums[nodeA];
                int valueB = nums[nodeB];
                int value0 = nums[0];
                if(children[nodeA][nodeB])
                {
                    valueA^=nums[nodeB];
                    value0^=nums[nodeA];
                }
                else if(children[nodeB][nodeA])
                {
                    valueB^=nums[nodeA];
                    value0^=nums[nodeB];
                }
                else
                {
                    value0 = value0^valueA^valueB;
                }
                score = min(score,max({valueA,valueB,value0})-min({valueA,valueB,value0}));
            }
        }
        return score;
    }
};