#include <stack>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		int removal = minvalid(s);
		solve(s, removal);
		return ans;
	}
private:
	int minvalid(string s){
		stack<int> st;
		for(auto it: s){
			if(it == '(')   st.push(it);
			else if(it == ')'){
				if(!st.empty() && st.top() == '(')
					st.pop();
				else    st.push(it);
			}
		}
		return st.size();
	}

	void solve(string s, int removal){
		if(stringParsed.count(s)>0)  return;
		else stringParsed.insert(s);

		if(removal==0 && minvalid(s) == 0)
		{
			ans.push_back(s);
			return;
		}
		
		for(int i=0;i<s.length();i++) solve(s.substr(0,i)+s.substr(i+1), removal-1);
	}

  unordered_set<string> stringParsed;
	vector<string> ans;
};