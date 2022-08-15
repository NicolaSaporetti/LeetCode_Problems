#include <iostream>
using namespace std;

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int index1 = -1;
        int index2 = -1;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
            {
                if(index1==-1)
                {
                    index1 = i;
                }
                else if(index2 == -1)
                {
                    index2 = i;
                }
                else return false;
            }
        }
        if(index1==-1 && index2 == -1) return true;
        else if(index1 !=-1 && index2 !=-1)
        {
            char temp = s1[index1];
            s1[index1]=s1[index2];
            s1[index2]= temp;
            if(s1.compare(s2)==0) return true;
            return false;
        }
        else return false;
    }
};