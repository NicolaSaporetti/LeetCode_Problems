#include <vector>
#include <map>
using namespace std;

class DetectSquares {
public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        numPoints[{point[0],point[1]}]++;
        x[point[0]].insert(point[1]);
    }
    
    int count(vector<int> point) {
        int res = 0;
        for(auto& y2 : x[point[0]])
        {
            if(y2==point[1]) continue;
            res+=addSquarePoint(point[0],point[1],point[0]+abs(y2-point[1]),y2);
            res+=addSquarePoint(point[0],point[1],point[0]-abs(y2-point[1]),y2);
        }
        return res;
    }
private:
    int addSquarePoint(int xP1, int yP1, int xP2 , int yP2)
    {
        return (x.find(xP2)!=x.end() && x[xP2].find(yP1)!=x[xP2].end() && x[xP2].find(yP2)!=x[xP2].end()) ? numPoints[{xP1,yP2}]*numPoints[{xP2,yP1}]*numPoints[{xP2,yP2}] : 0;
    }
    
    unordered_map<int,set<int>> x;
    map<pair<int,int>,int> numPoints;
};