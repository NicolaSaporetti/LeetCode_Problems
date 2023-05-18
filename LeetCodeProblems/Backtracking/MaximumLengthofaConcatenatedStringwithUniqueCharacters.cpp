#include <vector>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        removeWordWithDuplicateLetters(arr);
        sol.assign(26,false);
        maxV = 0;
        current_val = 0;
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
                current_val+=arr[i].size();
                maxV = max(maxV,current_val);
                check(i+1,arr);
                current_val-=arr[i].size();
                for(auto c : arr[i]) sol[c-'a']=false;
            }
        }
    }
    
    int maxV;
    int current_val;
    vector<bool> sol;
};