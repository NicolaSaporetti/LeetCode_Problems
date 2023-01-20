#include <vector>
using namespace std;

class Robot {
public:
    Robot(int width, int height) : width(width), height(height), cur(0) {
        pos.resize(4);
        s = false;
        sz = (width+height-2)*2;
        pos[0]={0,width-1};
        pos[1]={width,width+height-2};
        pos[2]={width+height-1,2*width+height-3};
        pos[3]={2*width+height-2,2*width+2*height-4};
    }
    
    void step(int num) {
        cur = (cur+num)%sz;
        s = true;
    }
    
    vector<int> getPos() {
        if(cur>=pos[0][0] && cur<=pos[0][1]) return {cur,0};
        else if(cur>=pos[1][0] && cur<=pos[1][1]) return {width-1,(cur-(width-1))};
        else if(cur>=pos[2][0] && cur<=pos[2][1]) return {width-1-(cur-(width+height-2)),height-1};
        else  return {0,height-1-(cur-(2*width+height-3))};
    }
    
    string getDir() {
        if(cur>=pos[0][0] && cur<=pos[0][1])
        {
            if(cur==0 && s) return "South";
            else return "East";
        }
        else if(cur>=pos[1][0] && cur<=pos[1][1]) return "North";
        else if(cur>=pos[2][0] && cur<=pos[2][1]) return "West";
        else return "South";
    }
    
    vector<vector<int>> pos;
    int sz;
    int cur;
    int width;
    int height;
    bool s;
};