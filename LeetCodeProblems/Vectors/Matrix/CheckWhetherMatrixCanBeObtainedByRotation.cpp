#include <iostream>
#include <vector>
#include <priority_queue>
using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        sz = mat.size();
        if(check90rotation(mat,target) || check180rotation(mat,target) || check270rotation(mat,target) || checkNorotation(mat,target)) return true;
        else return false;
    }
    
private:
    
    bool check90rotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(mat[i][j]!=target[j][sz-1-i]) return false;
            }
        }
        return true;
    }
    
    bool check180rotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(mat[i][j]!=target[sz-1-i][sz-1-j]) return false;
            }
        }
        return true;
    }
    
    bool check270rotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(mat[i][j]!=target[sz-1-j][i]) return false;
            }
        }
        return true;
    }
    
    bool checkNorotation(vector<vector<int>>& mat, vector<vector<int>>& target)
    {
        for(int i=0;i<sz;i++)
        {
            for(int j=0;j<sz;j++)
            {
                if(mat[i][j]!=target[i][j]) return false;
            }
        }
        return true;
    }
    
int sz;
};