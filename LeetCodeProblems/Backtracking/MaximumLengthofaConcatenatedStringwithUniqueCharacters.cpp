#include <vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        removeWordWithDuplicateLetters(arr);
        sol.assign(26,false);
        maxV = 0;
        check(0,arr);
        return maxV;
    }
    
private:
    void removeWordWithDuplicateLetters(vector<string>& arr)
    {
        int pos = 0;
        for(auto& word : arr)
        {
            vector<bool> v(26,false);
            bool wordContainsDuplication = false;
            for(auto c : word)
            {
                if(v[c-'a'])
                {
                    wordContainsDuplication = true;
                    break;
                }
                else v[c-'a']=true;
            }
            if(!wordContainsDuplication) arr[pos++] = word;
        }
        arr.resize(pos);
    }
    
    void check(int start, vector<string>& arr)
    {
        for(int i=start;i<arr.size();i++)
        {
            bool match = true;
            for(auto c : arr[i])
            {
                if(sol[c-'a'])
                {
                    match = false;
                    break;
                }
            }
            if(match)
            {
                for(auto c : arr[i]) sol[c-'a']=true;
                computeMax();
                check(i+1,arr);
                for(auto c : arr[i]) sol[c-'a']=false;
            }
        }
    }
    
    void computeMax()
    {
        int tot = 0;
        for(auto i : sol) if(i) tot++;
        maxV = max(maxV, tot);
    }
    
    int maxV;
    vector<int> sol;
};