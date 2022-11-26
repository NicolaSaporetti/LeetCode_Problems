#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        numbers = k;
		sum = n;
		addNumber(1);
		return solutions;
    }
private:
	void addNumber(int start)
	{
		if(sum==0 && numbers==0)
        {
            solutions.push_back(sol);
            return;
        }
        else if(sum<=0 || numbers<=0) return;
        else 
        {
            for(int i=start;i<10;i++)
            {
                sol.push_back(i);
                numbers--;
                sum-=i;
                addNumber(i+1);
                sol.pop_back();
                numbers++;
                sum+=i;
            }
        }
	}
    
    vector<vector<int>> solutions;
    vector<int> sol;
	int numbers;
	int sum;
};