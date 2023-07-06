#include <queue>
#include <multiset>
using namespace std;

class MKAverage {
public:
    MKAverage(int m, int k) {
        numE = m;
        rem = k;
        sum = 0;
    }
    
    void addElement(int num) {
        q.push(num);
        m.insert(num);
        if(q.size()==numE)
        {
            auto it = m.begin();
            for(int i=0;i<rem;i++)
            {
                it++;
            }
            bot = it;
            sum+=*it;
            for(int i=0;i<(numE-2*rem-1);i++)
            {
                it++;
                sum+=*it;
            }
            top = it;
        }
        else if(q.size()>numE)
        {
            insertNum(num);
            removeNum();
        }
    }
    
    int calculateMKAverage() {
        if(q.size()<numE) return -1;
        else return sum/(numE-2*rem);
    }
private:
    void insertNum(int num)
    {
        if(num>=*top)
        {
            top++;
            sum+=*top;
        }
        else if(num<*bot)
        {
            bot--;
            sum+=*bot;
        }
        else
        {
            sum+=num;
            m.insert(num);
        }
    }
    
    void removeNum()
    {
        int e = q.front();
        q.pop();
        if(e>*top)
        {
            sum-=*top;
            top--;
            m.erase(m.find(e));
        }
        else if(e==*top)
        {
            sum-=*top;
            m.erase(top--);
        }
        else if(e<*bot)
        {
            sum-=*bot;
            bot++;
            m.erase(m.find(e));
        }
        else if(e==*bot)
        {
            sum-=*bot;
            m.erase(bot++);
        }
        else
        {
            sum-=e;
            m.erase(m.find(e));
        }
    }
    
    queue<int> q;
    multiset<int> m;
    int sum;
    int numE;
    int rem;
    multiset<int>::iterator bot;
    multiset<int>::iterator top;
};