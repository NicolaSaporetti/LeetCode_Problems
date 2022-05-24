#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int>> solutions;
	int amountOfNumbers;
	int sum;
	void addNumber(vector<int>& tempSol, int lastNum, int tempSum)
	{
		if(tempSum>sum || (tempSum==sum && tempSol.size()<amountOfNumbers) || (tempSum<sum && tempSol.size()==amountOfNumbers))
		{
			return;
		}
		if(tempSol.size()==amountOfNumbers && tempSum==sum)
		{
			solutions.push_back(tempSol);
			return;
		}
		
		for(int i=lastNum+1;i<=10-amountOfNumbers+tempSol.size();i++)
		{
			tempSol.push_back(i);
			addNumber(tempSol,i,tempSum+i);
			tempSol.pop_back();
		}
	}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        amountOfNumbers = k;
		sum = n;
		vector<int> tempSol;
		addNumber(tempSol,0,0);
		return solutions;
    }
};

int main()
{
    Solution solution;
    return 0;
}