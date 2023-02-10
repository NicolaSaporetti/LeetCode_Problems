using namespace std;

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        w1.assign(26,0);
        w2.assign(26,0);
        for(auto& e: word1) w1[e-'a']++;
        for(auto& e: word2) w2[e-'a']++;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(computeDiff(i,j)) return true;
            }
        }
        return false;
    }
private:
    bool computeDiff(int i, int j)
    {
        if(w1[i]>0 && w2[j]>0)
        {
            int tot = 0;
            w1[i]--; w1[j]++;
            w2[i]++; w2[j]--;
            for(int i=0;i<26;i++)
            {
                tot +=(w1[i]>0)? 1 : 0;
                tot -=(w2[i]>0)? 1 : 0;
            }
            w1[i]++; w1[j]--;
            w2[i]--; w2[j]++;
            return !tot;
        }
        else return false;
        
    }
    
    vector<int> w1;
    vector<int> w2;
};