#include <vector>
#include "..\DD\FenwickTreeOneBasedIndexing.cpp"
using namespace std;


class Solution {
public:
    int numTeams(vector<int>& ratings) {
        n = ratings.size();
        maxi = *max_element(ratings.begin(), ratings.end());
        vector<int> smallerB = computeSmallerIBefore(ratings);
        vector<int> greaterA = computeGreaterIAfter(ratings);
        int first = 0;
        for(int i=0; i<n; i++){
            first += (smallerB[i] * greaterA[i]);
        }

        vector<int> smallerA = computeSmallerIAfter(ratings);
        vector<int> greaterB = computeGreaterIBefore(ratings);
        for(int i=0; i<n; i++){
            first += (smallerA[i] * greaterB[i]);
        }
        
        return first;
    }
private:
    vector<int> computeSmallerIBefore(vector<int>& ratings)
    {
        FenwickTreeOneBasedIndexing ft(maxi);
        vector<int> v(n, 0);
        for(int i=0; i<n; i++){
            v[i] = ft.sum(ratings[i]);
            ft.add(ratings[i], 1);
        }
        return v;
    }
    vector<int> computeSmallerIAfter(vector<int>& ratings)
    {
        FenwickTreeOneBasedIndexing ft(maxi);
        vector<int> v(n, 0);
        for(int i=n-1; i>=0; i--){
            v[i] = ft.sum(ratings[i]);
            ft.add(ratings[i], 1);
        }
        return v;
    }
    vector<int> computeGreaterIAfter(vector<int>& ratings)
    {
        FenwickTreeOneBasedIndexing ft(maxi);
        vector<int> v(n, 0);
        int num = 0;
        for(int i=n-1; i>=0; i--){
            v[i] = num - ft.sum(ratings[i]);
            ft.add(ratings[i], 1);
            num++;
        }
        return v;
    }
    vector<int> computeGreaterIBefore(vector<int>& ratings)
    {
        FenwickTreeOneBasedIndexing ft(maxi);
        vector<int> v(n, 0);
        int num = 0;
        for(int i=0;i<n;i++){
            v[i] = num - ft.sum(ratings[i]);
            ft.add(ratings[i], 1);
            num++;
        }
        return v;
    }

    int n;
    int maxi;
};