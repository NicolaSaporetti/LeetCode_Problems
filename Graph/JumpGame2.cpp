#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

typedef struct
{
    int weight;
    int number;
    bool evaluated;
} Node;

class Solution {
private:
    int sz;
    vector<Node> graph;
    unordered_set<Node*> elementsToEvaluate;
    void initializeNodes() {
        Node node;
        graph.resize(sz);
        for(int i=0;i<sz;i++)
        {
            node.number=i;
            node.weight=10000;
            graph[i]= node;
        }
        graph[0].weight=0;
        elementsToEvaluate.insert(&graph[0]);
    }
    Node* findElementToEvaluate() {
        Node* chosenNode = nullptr;
        unordered_set<Node*>::iterator current;
        int tempweight = 10000;
        //cout<<"Searching elements"<<endl;
        for(auto it=elementsToEvaluate.begin();it!=elementsToEvaluate.end();it++)
        {
            //cout<<"Element i("<<(*it)->number<<"). Weight: "<<(*it)->weight<<endl;
            if((*it)->weight<tempweight)
            {
                tempweight = (*it)->weight;
                current = it;
            }
        }
        chosenNode = *current;
        //cout<<"Selected element: "<<chosenNode->number<<endl;
        elementsToEvaluate.erase(current);
        return chosenNode;
    }
public:
    int jump(vector<int>& nums) {
        sz = nums.size();
        initializeNodes();
        do
        {
            Node* elem = findElementToEvaluate();
            if(elem->number == sz-1) return elem->weight;
            int current_weight = elem->weight;
            int num = elem->number;
            for(int i=1;i<=nums[num] && num+i<sz;i++)
            {
                if(!graph[num+i].evaluated)
                {
                    if(graph[num+i].weight>current_weight+1)
                    {
                        graph[num+i].weight=current_weight+1;
                        //cout<<"Updating weight: "<<graph[num+i].weight<<endl;
                        //cout<<"Adding element: "<<num+i<<endl;
                        elementsToEvaluate.insert(&graph[num+i]);
                    }
                }
            }
            elem->evaluated = true;
        }
        while(elementsToEvaluate.size()>0);
        return 0;
    }
};

int main()
{
    Solution solution;
    return 0;
}