using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int start = 0;
        int numT = 0;
        int numF = 0;
        int res = 0;
        for(int i=0;i<answerKey.size();i++)
        {
            if(answerKey[i]=='T') numT++;
            else numF++;
            while(i-start+1>numT+k && i-start+1>numF+k)
            {
                if(answerKey[start]=='T') numT--;
                else numF--;
                start++;
            }
            res = max(res,i-start+1);
        }
        return res;
    }
};