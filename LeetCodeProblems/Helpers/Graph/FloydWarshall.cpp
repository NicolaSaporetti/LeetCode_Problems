//set the distance on the cell
//to indicate bi-directional set ab and ba
//if no edge is present set very high number 1e9

void FloydWarshall(vector<vector<int>>& g)
{
    int n = g.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]); 
            }
        }
    }
}