#include <vector>
#include <array>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int sz = 0;
        for(int i=0;i<26;i++)
        {
            lettersBoundaries[i][0]=-1;
            lettersBoundaries[i][1]=-1;
        }
        for(int i=0;i<s.size();i++)
        {
            if(lettersBoundaries[s[i]-'a'][0]==-1)
            {
                lettersBoundaries[s[i]-'a'][0]=i;
                lettersBoundaries[s[i]-'a'][1]=i;
            }
            else lettersBoundaries[s[i]-'a'][1]=i;
        }
        return getBoundariesSize(s);
    }
private:  
    vector<int> getBoundariesSize(string const& s)
    {
        vector<int> boundariesSize;
        int rightSide = 0;
        int leftSide = 0;
        for(int i=0;i<s.size();i++)
        {
            rightSide = max(rightSide,lettersBoundaries[s[i]-'a'][1]);
            if(i+1>rightSide)
            {
                boundariesSize.push_back(rightSide-leftSide+1);
                leftSide = i+1;
            }
        }
        return boundariesSize;
    }

    array<array<int,2>,26> lettersBoundaries;
};