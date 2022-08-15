#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int row_sz;
    int col_sz;
    int color;
    int starting_col;
    
    void fill(vector<vector<int>>& image, int sr, int sc) {
        if(sr<row_sz && sr>=0 && sc<col_sz && sc>=0 && image[sr][sc]==starting_col)
        {
            image[sr][sc]=color;
            fill(image,sr+1,sc);
            fill(image,sr-1,sc);
            fill(image,sr,sc+1);
            fill(image,sr,sc-1);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        row_sz = image.size();
        col_sz = image[0].size();
        this->color = color;
        starting_col = image[sr][sc];
        if(image[sr][sc]!=color) fill(image,sr,sc);
        return image;
    }
};