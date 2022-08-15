#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef struct Node
{
    int row;
    int column;
    int effort;
    bool evaluated;
} Node;

class Solution {
private:
    vector<vector<Node>> nodes;
    unordered_set<Node*> active_nodes;
    int row_sz;
    int column_sz;
    void prepare_nodes()
    {
        nodes.resize(row_sz);
        for(int i=0;i<row_sz;i++)
        {
            nodes[i].resize(column_sz);
            for(int j=0;j<column_sz;j++)
            {
                nodes[i][j].row=i;
                nodes[i][j].column=j;
                nodes[i][j].effort=2000000;
                nodes[i][j].evaluated=false;
            }
        }
    }
    void prepare_start()
    {
        nodes[0][0].row=0;
        nodes[0][0].column=0;
        nodes[0][0].effort=0;
        nodes[0][0].evaluated=true;
        active_nodes.insert(&(nodes[0][0]));
    }
    Node* find_element()
    {
        Node* element=nullptr;
        int minEffort= 2000000;
            cout<<active_nodes.size()<<endl;
        for (auto it = active_nodes.cbegin(); it != active_nodes.cend(); ++it)
        {
            Node* temp =*it;
            if(minEffort>temp->effort)
            {
                minEffort=temp->effort;
                element = temp;
            }
        }
        return element;
    }
    void addDown(Node* element, vector<vector<int>>& heights, int row, int column)
    {
        if(row+1<row_sz)
        {
            addElement(element, heights, row+1, column, row, column);
        }
    }
    void addRight(Node* element, vector<vector<int>>& heights, int row, int column)
    {
        if(column+1<column_sz)
        {
            addElement(element, heights, row, column+1, row, column);
        }
    }
    void addUp(Node* element, vector<vector<int>>& heights, int row, int column)
    {
        if(row-1>=0)
        {
            addElement(element, heights, row-1, column, row, column);
        }
    }
    void addLeft(Node* element, vector<vector<int>>& heights, int row, int column)
    {
        if(column-1>=0)
        {
            addElement(element, heights, row, column-1, row, column);
        }
    }
    void addElement(Node* element, vector<vector<int>>& heights, int row, int column, int current_row, int current_column)
    {
        if(!nodes[row][column].evaluated)
        {
            int difference = max(abs(heights[row][column]-heights[current_row][current_column]),element->effort);
            if(nodes[row][column].effort>difference)
            {
                nodes[row][column].effort=difference;
                active_nodes.insert(&(nodes[row][column]));
            }
        }
    }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        row_sz=heights.size();
        column_sz=heights[0].size();
        int effort = -1;
        prepare_nodes();
        prepare_start();
        
        Node* element=find_element();
        while(element->row!=row_sz-1 || element->column!=column_sz-1)
        {
            addDown(element, heights, element->row, element->column);
            addRight(element, heights, element->row, element->column);
            addUp(element, heights, element->row, element->column);
            addLeft(element, heights, element->row, element->column);
            element->evaluated=true;
            active_nodes.erase(element);
            element=find_element();
        }
        return element->effort;
    }
};