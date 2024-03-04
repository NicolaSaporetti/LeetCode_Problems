#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    double getMinDistSum(vector<vector<int>>& positions) {
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        double x = 0.0;
        double y = 0.0;
        const double eps = 0.0000001;
        for(auto e : positions)
        {
            x+=e[0];
            y+=e[1];
        }
        x/=(double)positions.size();
        y/=(double)positions.size();
        double d = dist(x, y,positions);

        double step = 1.0;
        bool done = false;
        while ( step > eps )
        {
            done = 0;
            for ( int i = 0; i < 4; ++i )
            {
                double nx = x + step*dx[i];
                double ny = y + step*dy[i];

                double t = dist(nx, ny,positions);

                if ( t < d )
                {
                    d = t;
                    x = nx;
                    y = ny;
                    done = true;
                    break;
                }
            }
            if ( !done ) step /= 2;
        }
        return d;
    }
private:    
    double dist(double x, double y, vector<vector<int>>& positions)
    {
        double ret = 0;
        for ( int i = 0; i < positions.size(); ++i )
        {
            double dx = positions[i][0] - x;
            double dy = positions[i][1] - y;
            ret += sqrt(dx*dx + dy*dy);
        }
        return ret;
    }
};