#include <stack>
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
                if(!correctPath.empty()) correctPath.pop();
            }
            else correctPath.push(s);
	    }
    }
    
    string saveCorrectPathToString()
    {
        stack<string> temp;
        string res;
        while(!correctPath.empty())
        {
            temp.push(correctPath.top());
            correctPath.pop();
        }
        while(!temp.empty())
        {
            res+='/';
            res+=temp.top();
            temp.pop();
        }
        if(res=="") res+='/';
        return res;
    }
    
    stack<string> correctPath;
};