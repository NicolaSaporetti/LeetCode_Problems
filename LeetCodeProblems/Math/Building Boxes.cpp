using namespace std;

class Solution {
public:
    int minimumBoxes(int n) {
        long long edge = 0;
        long long base = 0;
        long long tot = 0;
        long long lim = n;
        while(tot+(edge+2)*(edge+1)/2<=lim)
        {
            tot+=(edge+2)*(edge+1)/2;
            edge++;
            base+=edge;
        }
        lim-=tot;
        for(long long i=0;lim>0;i++)
        {
            long long contri = (i+1)*i/2;
            if(contri>=lim)
            {
                base+=i;
                lim-=contri;
            }
        }
        return base;
    }
};