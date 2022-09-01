#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        fillNumbersAndOperations(s);
        if(operations.size()>0) executeMultiplicationAndDivision();
        if(operations.size()>0) executeAdditionAndSubtraction();
        return numbers.front();
    }
    
private:
    void fillNumbersAndOperations(string& s)
    {
        int start = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/') operations.push(s[i]);
            else if(s[i]-'0'>=0 && s[i]-'0'<=9)
            {
                start = i;
                while(i<s.size() && s[i]-'0'>=0 && s[i]-'0'<=9) i++;
                numbers.push(stoi(s.substr(start,i-start)));
                i--;
            }
        }
    }
    
    void executeMultiplicationAndDivision()
    {
        int operationsNum = operations.size();
        long long operand1 = numbers.front();
        numbers.pop();
        for(int i=0;i<operationsNum;i++)
        {
            long long operand2= numbers.front();
            numbers.pop();
            if(operations.front()=='*' || operations.front()=='/')
            {
                operand1 = performOperation(operand1, operand2, operations.front());
            }
            else
            {
                operations.push(operations.front());
                numbers.push(operand1);
                operand1 = operand2;
            }
            operations.pop();
        }
        numbers.push(operand1);
    }
    
    void executeAdditionAndSubtraction()
    {
        long long operand1 = numbers.front();
        numbers.pop();
        while(!operations.empty())
        {
            long long operand2= numbers.front();
            numbers.pop();
            operand1 = performOperation(operand1, operand2, operations.front());
            operations.pop();
        }
        numbers.push(operand1);
    }
    
    long long performOperation(long long op1, long long op2, char operation)
    {
        if(operation =='+') return op1+op2;
        else if(operation =='-') return op1-op2;
        else if(operation =='*') return op1*op2;
        else return op1/op2;
    }
    
    queue<long long> numbers;
    queue<char> operations;
};