#include <vector>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<vector<bool>> k(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
            for(int j=0;j<languages[i].size();j++)
                k[i][languages[i][j]-1] = true;
        vector<int> graph(m,0);
        for(auto& e : friendships)
        {
            int p1 = e[0]-1;
            int p2 = e[1]-1;
            bool friendCanSpeak = false;
            for(int i=0;i<n && !friendCanSpeak;i++) if(k[p1][i] && k[p2][i]) friendCanSpeak=true;
            if(!friendCanSpeak)
            {
                graph[p1]++;
                graph[p2]++;
            }
        }
        vector<int> kl(n,0);
        for(int i=0;i<m;i++)
        {
            if(graph[i]!=0)
            {
                for(int j=0;j<n;j++)
                {
                    if(!k[i][j]) kl[j]++;
                }
            }
        }
        return *min_element(begin(kl),end(kl));
    }
};