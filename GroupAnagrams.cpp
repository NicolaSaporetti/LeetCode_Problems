#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Solution {
private:
    void order(string& s)
    {
        for(int i=0; i< s.size(); i++)
        {
            for(int j=i+1; j< s.size(); j++)
            {
                cout<<"Here1"<<endl;
                if(s[i]>s[j])
                {
                    char temp = s[j];
                    s[j] = s[i];
                    s[i] = temp;
                }
            }
        }
    }

    int findSameLetterComposition(vector<string>& identifier, string& temp)
    {
        for(int i=0;i<identifier.size();i++)
        {
            if(identifier[i].compare(temp) == 0)
            {
                return i;
            }
        }
        return -1;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> sol;
        vector<string> identifier;
        for(int i=0;i<strs.size();i++)
        {
            string temp = strs[i];
            order(temp);
            int cellNumber = findSameLetterComposition(identifier,temp);
            if(cellNumber==-1)
            {
                identifier.push_back(temp);
                vector<string> newWordComp;
                newWordComp.push_back(strs[i]);
                sol.push_back(newWordComp);
            }
            else{
                sol[cellNumber].push_back(strs[i]);
            }
        }
        return sol;    
    }
};

int main()
{
    vector<string> anagrams = {""};
    Solution solution;
    vector<vector<string>> sol = solution.groupAnagrams(anagrams);
    for(int i=0; i< sol.size(); i++)
    {
        for(int j=0; j< sol[i].size(); j++)
        {   
            cout<<sol[i][j]<<endl;
        }
    }
    return 0;
}