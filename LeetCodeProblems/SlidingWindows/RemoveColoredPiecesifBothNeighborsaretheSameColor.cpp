using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int moveA = computeMoves(colors,'A');
        int moveB = computeMoves(colors,'B');
        return moveA>moveB;
    }
private:
    int computeMoves(string& colors, char let)
    {
        int sz = colors.size();
        int szc = 0;
        int totC = 0;
        for(int i=0;i<sz;i++)
        {
            if(colors[i]==let) szc++;
            else
            {
                if(szc>=3) totC+=(szc-2);
                szc=0;
            }
        }
        if(szc>=3) totC+=(szc-2);
        return totC;
    }
};