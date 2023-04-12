#include <vector>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        temp.assign(n,0);
        computeNumbers(0,k);
        return result;
    }
private:
    void computeNumbers(int pos,int diff)
    {
        if(pos==0)
        {
            for(int i=1;i<=9;i++)
            {
                temp[pos]=i;
                computeNumbers(pos+1,diff);
            }
        }
        else if(pos==temp.size()) addNumToResult();
        else
        {
            temp[pos]=temp[pos-1]+diff;
            if(temp[pos]<=9) computeNumbers(pos+1,diff);
            if(diff!=0)
            {
                temp[pos]=temp[pos-1]-diff;
                if(temp[pos]>=0) computeNumbers(pos+1,diff);
            }
        }
    }

    void addNumToResult()
    {
        int num = 0;
        for(int j=0;j<temp.size();j++)
        {
            num*=10;
            num+=temp[j];
        }
        result.push_back(num);
    }

    vector<int> temp;
    vector<int> result;
};