#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> solution(m,vector<int>(n,-1));
        int row = 0;
        int col = 0;
        int remainingRow = m;
        int remainingCol = n;
        while(remainingRow>0 && remainingCol>0)
        {
            if(remainingRow>0) {
                for(int i=0;i<remainingCol;i++)
                {
                    if(head!=nullptr)
                    {
                        solution[row][col++] = head->val;
                        head = head->next;
                    }
                    else return solution;
                }
                row++;
                col--;
                remainingRow--;
            }
            if(remainingCol>0) {
                for(int i=0;i<remainingRow;i++)
                {
                    if(head!=nullptr)
                    {
                        solution[row++][col] = head->val;
                        head = head->next;
                    }
                    else return solution;
                }
                col--;
                row--;
                remainingCol--;
            }
            if(remainingRow>0) {
                for(int i=0;i<remainingCol;i++)
                {
                    if(head!=nullptr)
                    {
                        solution[row][col--] = head->val;
                        head = head->next;
                    }
                    else return solution;
                }
                row--;
                col++;
                remainingRow--;
            }
            if(remainingCol>0) {
                for(int i=0;i<remainingRow;i++)
                {
                    if(head!=nullptr)
                    {
                        solution[row--][col] = head->val;
                        head = head->next;
                    }
                    else return solution;
                }
                col++;
                row++;
                remainingCol--;
            }
        }
        return solution;
    }
};