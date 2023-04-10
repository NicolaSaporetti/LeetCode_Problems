#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int totalStrength(vector<int>& strength) {
        size = strength.size();
        MOD = 1000000007L;
        
        vector<long long>rightPrefixSum = makeRightPrefixSum(strength); 
        vector<long long>rightPrefixSumPrefixSum = makeRightPrefixSumPrefixSum(strength,rightPrefixSum);
        
        vector<long long>leftPrefixSum = makeLeftPrefixSum(strength); 
        vector<long long>leftPrefixSumPrefixSum = makeLeftPrefixSumPrefixSum(strength,leftPrefixSum);
        
        vector<int> rightIndexes = makeRightIndexes(strength);
        vector<int> leftIndexes = makeLeftIndexes(strength);
        
        for(int i=0;i<size;i++) cout<<rightIndexes[i]<<" ";
        cout<<endl;
        for(int i=0;i<size;i++) cout<<leftIndexes[i]<<" ";
        cout<<endl;
        
        int leftIndex,rightIndex;
        long long rightSum, leftSum,totalSum,leftSize,rightSize;
        
        // sum of all subarray strengths
        long long totalStrength = 0L;
        
        for(int i=0;i<size;i++)
        {            
            // left index => max (left index, previous index of current value)
            leftIndex = leftIndexes[i];
            rightIndex = rightIndexes[i];
            
            // get left and right subarray size from current index inclusive
            leftSize = i - leftIndex + 1;
            rightSize = rightIndex - i + 1;
            
            // rigth subarrays sum from prefix sum of prefix sum from left to right
            rightSum = rightPrefixSumPrefixSum[rightIndex] - (i>0 ? rightPrefixSumPrefixSum[i-1] + (rightPrefixSum[i-1] * rightSize) : 0L);
            
            // left subarrays sum from prefix sum of prefix sum from right to left
            leftSum = leftPrefixSumPrefixSum[leftIndex] - (i<size-1 ? leftPrefixSumPrefixSum[i+1] + (leftPrefixSum[i+1] * leftSize) : 0L);                
            
            // total subarray sums => left sum * right size + right sum * left size - current value * left size * right size            
            totalSum = ((rightSum%MOD * leftSize) + (leftSum%MOD * rightSize) - ((long long)strength[i] * (leftSize * rightSize)) + MOD)%MOD;
            
            totalStrength = (totalStrength + (totalSum * (long long)strength[i])%MOD ) %MOD;
        }
        
        return totalStrength;
    }
    
    vector<long long> makeRightPrefixSum(vector<int>& strength)
    {
        vector<long long>rightPrefixSum(size);        
        rightPrefixSum[0] = strength[0];
        
        for(int i=1;i<size;i++)
        {
            rightPrefixSum[i] = rightPrefixSum[i-1] + strength[i];
        }
        return rightPrefixSum;
    }
    
    vector<long long> makeRightPrefixSumPrefixSum(vector<int>& strength, vector<long long>& rightPrefixSum)
    {
        vector<long long>rightPrefixSumPrefixSum(size);
        rightPrefixSumPrefixSum[0] = strength[0];
        
        for(int i=1;i<size;i++)
        {
            rightPrefixSumPrefixSum[i] = rightPrefixSumPrefixSum[i-1] + rightPrefixSum[i];
        }
        return rightPrefixSumPrefixSum;
    }
    
    vector<long long> makeLeftPrefixSum(vector<int>& strength)
    {
        vector<long long>leftPrefixSum(size);
        leftPrefixSum[size-1] = strength[size-1];
        
        for(int i=size-2;i>=0;i--)
        {
            leftPrefixSum[i] = leftPrefixSum[i+1] + strength[i];
        }
        return leftPrefixSum;
    }
    
    vector<long long> makeLeftPrefixSumPrefixSum(vector<int>& strength,vector<long long>& leftPrefixSum)
    {
        vector<long long>leftPrefixSumPrefixSum(size);
        leftPrefixSumPrefixSum[size-1] = strength[size-1];
        
        for(int i=size-2;i>=0;i--)
        {
            leftPrefixSumPrefixSum[i] = leftPrefixSumPrefixSum[i+1] + leftPrefixSum[i];
        }
        return leftPrefixSumPrefixSum;
    }
    
    vector<int> makeRightIndexes(vector<int>& strength)
    {
        vector<int>rightIndexes(size);
        stack<int>rstak;
        
        for(int i=size-1;i>=0;i--)
        {
            while(!rstak.empty() && strength[rstak.top()]>=strength[i])rstak.pop();
            
            rightIndexes[i] = rstak.empty() ? size-1 : rstak.top() - 1;
            
            rstak.push(i);
        }
        return rightIndexes;
    }
    
    
    vector<int> makeLeftIndexes(vector<int>& strength)
    {
        vector<int> leftIndexes(size);
        stack<int> lstak;  
        
        for(int i=0;i<size;i++)
        {
            while(!lstak.empty() && strength[lstak.top()]>strength[i])lstak.pop();
            
            leftIndexes[i] = lstak.empty() ? 0 : lstak.top() + 1;
            
            lstak.push(i);
        }
        return leftIndexes;
    }
private:
    int size;
    long long MOD;
};