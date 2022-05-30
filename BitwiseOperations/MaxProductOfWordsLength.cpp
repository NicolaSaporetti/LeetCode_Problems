#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> mask;
public:
    int maxProduct(vector<string>& words) {
        int res = 0;
        mask.resize(words.size());
        for(int i=0;i<words.size();i++)
        {
            mask[i]=0;
            for(int j=0;j<words[i].size();j++)
            {
                mask[i]|=1<<(words[i][j]-'a');
            }
            for(int j=0;j<i;j++)
            {
                if((mask[i]&mask[j])==0) res = max(res, int(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    return 0;
}