#include <vector>
using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) : b(balance), sz(balance.size()) {
    }
    
    bool transfer(int account1, int account2, long long money) {
        account1--;
        account2--;
        if(account1<sz && account2<sz && b[account1]>=money)
        {
            b[account2]+=money;
            b[account1]-=money;
            return true;
        }
        else return false;
    }
    
    bool deposit(int account, long long money) {
        account--;
        if(account<sz)
        {
            b[account]+=money;
            return true;
        }
        else return false;
    }
    
    bool withdraw(int account, long long money) {
        account--;
        if(account<sz && b[account]>=money)
        {
            b[account]-=money;
            return true;
        }
        else return false;
    }
    
    vector<long long> b;
    int sz;
};