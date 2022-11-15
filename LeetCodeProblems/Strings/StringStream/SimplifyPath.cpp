#include <deque>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        buildCorrectPath(path);
        return saveCorrectPathToString();
    }
private:
    void buildCorrectPath(string& path)
    {
        stringstream stream(path);
	    string s;
	    while (getline(stream, s, '/')) {
            if(s=="." || s=="");
            else if(s=="..")
            {
                if(!correctPath.empty()) correctPath.pop_back();
            }
            else correctPath.push_back(s);
	    }
    }
    
    string saveCorrectPathToString()
    {
        string res;
        while(!correctPath.empty())
        {
            res+='/'+correctPath.front();
            correctPath.pop_front();
        }
        return (res.size()==0)? "/" : res;
    }
    
    deque<string> correctPath;
};