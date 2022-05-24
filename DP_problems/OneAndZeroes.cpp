class Solution {
private:
    array<map<int,int>,101> zeroesArr;
    array<map<int,int>,101> onesArr;

    void fillArrays(vector<string>& strs, int m, int n)
    {
        for(int i=0;i<strs.size();i++)
        {
            int zeroes = 0;
            int ones = 0;
            for(int j=0;j<strs[i].size();j++)
            {
                if(strs[i][j]=='0') zeroes++;
                else ones++;
            }
            if(zeroes<=m && ones<=n)
            {
                zeroesArr[zeroes].insert(pair(i,ones));
                onesArr[ones].insert(pair(i,zeroes));
            }
        }
    }

    int selectBestElemZero(int ZeroamountLeft, int OneamountLeft, int& currentMinAmount)
    {
        int elem = -1;
        while(currentMinAmount<=ZeroamountLeft && elem==-1)
        {
            if(!zeroesArr[currentMinAmount].empty())
            {
                int min = INT_MAX;
                for(auto it=zeroesArr[currentMinAmount].begin();it!=zeroesArr[currentMinAmount].end();it++)
                {
                    if(min>it->second && OneamountLeft>=it->second)
                    {
                        min = it->second;
                        elem = it->first;
                    }
                }
                break;
            }
            else
            {
                currentMinAmount++;
            }
        }
        return elem;
    }

    int selectBestElemOne(int ZeroamountLeft, int OneamountLeft, int& currentMinAmount)
    {
        int elem = -1;
        while(currentMinAmount<=OneamountLeft && elem==-1)
        {
            if(!onesArr[currentMinAmount].empty())
            {
                int min = INT_MAX;
                for(auto it=onesArr[currentMinAmount].begin();it!=onesArr[currentMinAmount].end();it++)
                {
                    if(min>it->second && ZeroamountLeft>=it->second)
                    {
                        min = it->second;
                        elem = it->first;
                    }
                }
                break;
            }
            else
            {
                currentMinAmount++;
            }
        }
        return elem;
    }

    int isZeroElTheSelectedELement(int zeroesAmount, int onesAmount, int zeroEl, int oneEl, int m, int n)
    {
        auto it= zeroesArr[zeroesAmount].find(zeroEl);
        auto it2= onesArr[onesAmount].find(oneEl);
        double zeroPoint = double(zeroesAmount)/double(m) + double(it->second)/double(n);
        double onePoint =  double(it2->second)/double(m) +double(onesAmount)/double(n);
        cout<<"Zero  0: "<<zeroesAmount<<", 1: "<<it->second<<endl;
        cout<<"One  1: "<<onesAmount<<", 0: "<<it2->second<<endl;
        cout<<"Zero points: "<<zeroPoint<<", One points: "<<onePoint<<endl;
        if(abs(zeroPoint-onePoint)>0.00001)
        {
            return zeroPoint<onePoint? true : false;
        }
        else{
            if(m>n) return true;
            else return false;
        }
    }

    int selectBestElem(int& m, int& n, int zeroesAmount, int onesAmount)
    {
        int zeroEl = selectBestElemZero(m, n, zeroesAmount);
        int oneEl = selectBestElemOne(m, n, onesAmount);
        cout<<"Best zero: "<<zeroEl<<", Best one: "<<oneEl<<endl;
        if(zeroEl==-1 && oneEl == -1)
        {
            cout<<"No element left"<<endl;
            return -1;
        }
        else if(oneEl==zeroEl)
        {
            cout<<"Same element selected: "<<oneEl<<endl;
            m-=zeroesAmount;
            zeroesArr[zeroesAmount].erase(zeroEl);
            n-=onesAmount;
            onesArr[onesAmount].erase(oneEl);
            return oneEl;
        }
        else
        {
            cout<<"Different element selected"<<endl;
            if(oneEl == -1 || (zeroEl!=-1 && isZeroElTheSelectedELement(zeroesAmount, onesAmount, zeroEl, oneEl, m, n)))
            {
                cout<<"Element selected: "<<zeroEl<<endl;
                auto it= zeroesArr[zeroesAmount].find(zeroEl);
                m-=zeroesAmount;
                n-=it->second;
                onesArr[it->second].erase(zeroEl);
                zeroesArr[zeroesAmount].erase(zeroEl);
                return zeroEl;
            }
            else{
                cout<<"Element selected: "<<oneEl<<endl;
                auto it= onesArr[onesAmount].find(oneEl);
                m-=it->second;
                n-=onesAmount;
                zeroesArr[it->second].erase(oneEl);
                onesArr[onesAmount].erase(oneEl);
                return oneEl;
            }
        }
    }

    int maxSetSelected(int m, int n)
    {
        int zeroesAmount = 0;
        int onesAmount = 0;
        cout<<"Current 0: "<<m<<", 1: "<<n<<endl;
        int selected_elem = selectBestElem(m, n, zeroesAmount, onesAmount);
        int total = 0;
        while(selected_elem!=-1)
        {
            cout<<"NewElemSelected"<<endl;
            total++;
            cout<<"Current 0: "<<m<<", 1: "<<n<<endl;
            selected_elem = selectBestElem(m, n, zeroesAmount, onesAmount);
        }
        return total;
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        fillArrays(strs,m,n);
        return maxSetSelected(m, n);
    }
};