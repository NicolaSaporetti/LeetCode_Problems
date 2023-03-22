#include <vector>
using namespace std;

class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index++;
    }
    
    void visit(string url) {
        history.resize(index+1);
        history.push_back(url);
        index++;
    }
    
    string back(int steps) {
       index-=steps;
       if(index<0) index = 0;
        return history[index];
    }
    
    string forward(int steps) {
        index = min((int)history.size()-1, index+steps);
        return history[index];
    }
    vector<string> history;
    int index = -1;
};