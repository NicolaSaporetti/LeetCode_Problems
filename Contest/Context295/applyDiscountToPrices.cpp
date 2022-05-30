class Solution {
private:
    string result;
    int price;
    void printNum(long long n)
    {
        result.push_back('$');
        result += to_string(n/100);
        result.push_back('.');
        if(n%100 < 10)
        {
            result.push_back('0');
            result += to_string(n%10);
        }
        else result += to_string(n%100);
    }
    void printDiscount(string& s, int start, int end)
    {
        bool correct = false;
        long long number = 0;
        if(s[start]=='$')
        {
            for(int j=1;j<=10 && j+start<s.size() && s[start+j]!=' ';j++)
            {
                if(s[start+j]<48 || s[start+j]>57)
                {
                    correct = false;
                    break;
                }
                else
                {
                    correct = true;
                    number *=10;
                    number +=(s[start+j]-48);
                }
            }
        }
        
        if(correct)
        {
            number*=price;
            printNum(number);
        }
        else
        {
            for(int i=start;i<=end;i++)
            {
                result.push_back(s[i]);
            }
        }
    }
    
    void extractWords(string& s)
    {
        int start = 0;
        int end = 0;
        for(int i=0;i<s.size();i++)
        {
            start = i;
            while(i<s.size() && s[i]!=' ')
            {
                i++;
            }
            end = i-1;
            printDiscount(s,start,end);
            if(i<s.size()) result.push_back(' ');
        }
    }
public:
    string discountPrices(string sentence, int discount) {
        price = 100-discount;
        extractWords(sentence);
        return result;
    }
};