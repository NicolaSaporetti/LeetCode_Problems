#include <vector>
#include "DisjoinSetUnion.cpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) edges[i].push_back(i);
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {return a[2] < b[2];});
        
        DisjoinSetUnion dsu(n);
        int mstWeight = 0;
        for (int i = 0; i < m; ++i) {
            if (!dsu.are_connect(edges[i][0],edges[i][1]))
            {
                dsu.connect(edges[i][0], edges[i][1]);
                mstWeight += edges[i][2];
            }
        }
        
        vector<int> critical, pseudoCritical;
        for (int i = 0; i < m; ++i) {
            DisjoinSetUnion tempDsu(n);
            int weightWithout = 0;
            for (int j = 0; j < m; ++j) {
                if (i != j && !tempDsu.are_connect(edges[j][0], edges[j][1]))
                {
                    tempDsu.connect(edges[j][0], edges[j][1]);
                    weightWithout += edges[j][2];
                }
            }
            
            if (tempDsu.get_sets() != 1 || weightWithout > mstWeight) critical.push_back(edges[i][3]);
            else {
                DisjoinSetUnion newDsu(n);
                newDsu.connect(edges[i][0], edges[i][1]);
                int weightWith = edges[i][2];
                for (int j = 0; j < m; ++j) {
                    if (i != j && !newDsu.are_connect(edges[j][0], edges[j][1]))
                    {
                        newDsu.connect(edges[j][0], edges[j][1]);
                        weightWith += edges[j][2];
                    }
                }
                
                if (weightWith == mstWeight) pseudoCritical.push_back(edges[i][3]);
            }
        }
        return {critical, pseudoCritical};
    }
};