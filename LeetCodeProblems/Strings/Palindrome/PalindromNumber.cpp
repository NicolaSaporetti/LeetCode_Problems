using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        else
        {
            vector<int> number;
            while (x>0)
            {
                number.push_back(x%10);
                x/=10;
            }
            return checkPalindrome(number);
        }
    }
    
private:
    bool checkPalindrome(vector<int>& number)
    {
        bool isPalindrom = true;
        for(int i=0; i<number.size()/2; i++)
        {
            if(number[i]!=number[number.size()-1-i])
            {
                isPalindrom = false;
                break;
            }
        }
        return isPalindrom;
    }
};