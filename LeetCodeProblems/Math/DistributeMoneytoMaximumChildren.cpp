using namespace std;

class Solution {
public:
    int distMoney(int money, int children) {
        int tot = 0;
        if(money<children || (money==4 && children==1)) return -1;
        money-=children;
        while(children>0 && money>=7)
        {
            children--;
            money-=7;
            tot++;
        }
        if(children==0)
        {
            if(money!=0) tot--;
        }
        else
        {
            if(children==1 && money ==3) tot--;
        }
        return tot;
    }
};