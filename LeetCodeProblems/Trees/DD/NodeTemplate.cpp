#include <vector>
using namespace std;

template<class T>
class Node {
public:
    T val;
    vector<Node*> children;

    Node() {}

    Node(T _val) {
        val = _val;
    }

    Node(T _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};