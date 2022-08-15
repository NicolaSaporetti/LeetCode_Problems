#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> magazineComp(26,0);
        vector<int> ransomComp(26,0);
        int szRansom = ransomNote.size();
        int szMag = magazine.size();
        
        for(int i=0;i<szRansom;i++)
        {
            ransomComp[ransomNote[i]-'a']++;
        }
        for(int i=0;i<szMag;i++)
        {
            magazineComp[magazine[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            if(ransomComp[i]>magazineComp[i]) return false;
        }
        return true;
    }
};