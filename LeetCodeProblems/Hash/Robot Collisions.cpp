#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        sz = positions.size();
        vector<int> pos = computeOrderedPos(positions,healths,directions);
        map<int,int> result = computeRobotFinalPosAndHealth(healths,directions,pos);
        vector<int> res;
        for(auto& [key,val] : result) res.push_back(val);
        return res;
    }
private:
    vector<int> computeOrderedPos(vector<int>& positions, vector<int>& healths, string& directions)
    {
        map<int,vector<int>> m;
        vector<int> pos(sz,0);
        for(int i=0;i<sz;i++)
        {
            int dir = (directions[i]=='L')? 0 : 1;
            m[positions[i]]={i,healths[i],dir};
        }
        int j=0;
        for(auto& [key,vec] : m)
        {
            pos[j]=vec[0];
            healths[j]=vec[1];
            directions[j]=(vec[2]==0)? 'L' : 'R';
            j++;
        }
        return pos;
    }
    
    map<int,int> computeRobotFinalPosAndHealth(vector<int>& healths, string directions, vector<int>& pos)
    {
        map<int,int> posAndHealth;
        stack<pair<int,int>> st;
        for(int i=0;i<sz;i++)
        {
            if(directions[i]=='L')
            {
                if(st.empty()) posAndHealth[pos[i]]=healths[i];
                else
                {
                    while(!st.empty() && st.top().first<healths[i])
                    {
                        healths[i]--;
                        st.pop();
                    }
                    if(healths[i]==0) continue;
                    if(!st.empty() && st.top().first==healths[i])
                    {
                        st.pop();
                        continue;
                    }
                    if(!st.empty() && st.top().first>healths[i])
                    {
                        st.top().first--;
                        continue;
                    }
                    posAndHealth[pos[i]]=healths[i];
                }
            }
            else
            {
                st.push({healths[i],pos[i]});
            }
        }
        
        while(!st.empty())
        {
            posAndHealth[st.top().second]=st.top().first;
            st.pop();
        }
        return posAndHealth;
    }
    
    int sz;
};