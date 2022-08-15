#include <vector>
using namespace std;

class DisjoinSet {
public:
    DisjoinSet(int sz);

    int find_root(int x);
    
    void connect(int x, int y);

    int get_sets();
    
    bool are_connect(int x, int y);

private:
vector<int> root;
vector<int> heigth;
};