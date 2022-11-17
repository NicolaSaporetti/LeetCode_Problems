#include <vector>
#include "Node.cpp"
using namespace std;

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Nhead = nullptr;
        if(head ==nullptr) return Nhead;
        else
        {
            setUpArrays(head);
            Node* temp = Nhead;
            while(head!=nullptr)
            {
                if(head->random!=nullptr) setRandom(head->random, temp);
                temp = temp->next;
                head=head->next;
            }
            return Nhead;
        }
    }
private:
    void setUpArrays(Node* head)
    {
        Nhead = new Node(head->val);
        old_nodes.push_back(head);
        new_nodes.push_back(Nhead);
        head = head->next;
        Node* temp = Nhead;
        while(head!=nullptr)
        {
            old_nodes.push_back(head);
            temp->next = new Node(head->val);
            head = head->next;
            temp = temp->next;
            new_nodes.push_back(temp);
        }
    }
    
    void setRandom(Node* old_node, Node* new_node)
    {
        for(int i=0;i<old_nodes.size();i++)
        {
            if(old_nodes[i]==old_node)
            {
                new_node->random = new_nodes[i];
                break;
            }
        }
    }
    
    Node* Nhead;
    vector<Node*> old_nodes;
    vector<Node*> new_nodes;
};