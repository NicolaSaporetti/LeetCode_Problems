#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    bool checkOddPalindrome(vector<int>& number)
    {
        bool isPalindrom = true;
        int center = (number.size()-1)/2;
        for(int i=1; i<=center; i++)
        {
            if(number[center-i]!=number[center+i])  isPalindrom = false;
        }
        return isPalindrom;
    }
    
    bool checkEvenPalindrome(vector<int>& number)
    {
        bool isPalindrom = true;
        int right = number.size()/2;
        int left = number.size()/2-1;
        for(int i=0; i<number.size()/2; i++)
        {
            if(number[left-i]!=number[right+i])  isPalindrom = false;
        }
        return isPalindrom;
    }
public:
    bool isPalindrome(int x) {
        bool isPal = false;
        if(x<0)
        {
            return false;
        }
        else
        {
            int number_of_digit =1;
            vector<int> number;
            do
            {
                number.push_back(x%10);
                x/=10;
            } while (x!=0);
            
            if(number.size()%2==0)
            {
                return checkEvenPalindrome(number);
            }
            else{
                return checkOddPalindrome(number);
            }
        }
    }
};