#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        rz = image.size();
        cz = image[0].size();
        this->color = color;
        starting_col = image[sr][sc];
        if(image[sr][sc]!=color) fill(image,sr,sc);
        return image;
    }
private:
    void fill(vector<vector<int>>& image, int sr, int sc) {
        if(sr<rz && sr>=0 && sc<cz && sc>=0 && image[sr][sc]==starting_col)
        {
            image[sr][sc]=color;
            fill(image,sr+1,sc);
            fill(image,sr-1,sc);
            fill(image,sr,sc+1);
            fill(image,sr,sc-1);
        }
    }

    int rz;
    int cz;
    int color;
    int starting_col;
};