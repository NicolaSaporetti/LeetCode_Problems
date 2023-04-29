class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long apples = 0;
        long long edge = 0;
        while(apples<neededApples)
        {
            edge+=2;
            long long v1 = edge*(edge+1)/2;
            long long v2 = (edge/2-1)*(edge/2)/2;
            long long v3 = edge*(edge-1)/2;
            long long v4 = (edge/2)*(edge/2+1)/2;
            apples += (v1-v2+v3-v4)*4;
        }
        return edge*4;
    }
};