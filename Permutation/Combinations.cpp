#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> solutions;
	vector<int> solution;
	int lenght;
	int numbers;
	void computePermutations(int level) {
		int i = 1;
		if(level != lenght)
		{
			if(level) i = solution[level-1] + 1;
			for(;i<=numbers;i++)
			{
				solution.push_back(i);
				computePermutations(level+1);
				solution.pop_back();
			}
		}
		else
		{
			solutions.push_back(solution);
		}
    }
public:
    vector<vector<int>> combine(int n, int k) {
        lenght = k;
        numbers = n;
        computePermutations(0);
        return solutions;
    }
};