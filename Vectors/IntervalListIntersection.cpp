class Solution {
private:
    vector<vector<int>> solutions;
    vector<int> sol;
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.size() >=1 && secondList.size()>=1)
        {
            sol.resize(2);
            int j = 0;
            int i = 0;
            while(i<firstList.size() && j<secondList.size())
            {
                if(firstList[i][0]<=secondList[j][1] && secondList[j][0]<=firstList[i][1])
                {
                    sol[0] = max(firstList[i][0],secondList[j][0]);
                    sol[1] = min(firstList[i][1],secondList[j][1]);
                    solutions.push_back(sol);
                }
                if(firstList[i][1]>=secondList[j][1]) j++;
                else i++;
            }
        }
        return solutions;
    }
};