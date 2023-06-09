using namespace std;

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int num1 = 0;
        for(int i=0;i<firstWord.size();i++)
        {
            num1*=10;
            num1+=(firstWord[i]-'a');
        }
        int num2 = 0;
        for(int i=0;i<secondWord.size();i++)
        {
            num2*=10;
            num2+=(secondWord[i]-'a');
        }
        int num3 = 0;
        for(int i=0;i<targetWord.size();i++)
        {
            num3*=10;
            num3+=(targetWord[i]-'a');
        }
        return num1+num2==num3;
    }
};