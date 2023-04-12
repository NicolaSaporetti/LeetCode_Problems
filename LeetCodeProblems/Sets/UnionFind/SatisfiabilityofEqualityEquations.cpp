#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        equal.resize(26);
        not_equal.resize(26);
        visited.assign(26,0);
        for(auto& e : equations)
        {
            if(e[1]=='!')
            {
                not_equal[e[0]-'a'].push_back(e[3]-'a');
                not_equal[e[3]-'a'].push_back(e[0]-'a');
            }
            else
            {
                equal[e[0]-'a'].push_back(e[3]-'a');
                equal[e[3]-'a'].push_back(e[0]-'a');
            }
        }
        for(int i=0;i<26;i++)
        {
            s = {};
            if(!visited[i])
            {
                visited[i]=true;
                s.insert(i);
                addEquals(i);
            }
            if(!setIsCorrect()) return false;
        }
        return true;
    }
private:
    void addEquals(int el)
    {
        for(auto& adj : equal[el])
        {
            if(!visited[adj])
            {
                s.insert(adj);
                visited[adj]=true;
                addEquals(adj);
            }

        }
    }

    bool setIsCorrect()
    {
        for(auto& e : s)
        {
            for(auto& violation : not_equal[e]) if(s.count(violation)>0) return false;
        }
        return true;
    }

    vector<vector<char>> equal;
    vector<vector<char>> not_equal;
    vector<bool> visited;
    unordered_set<int> s;
};