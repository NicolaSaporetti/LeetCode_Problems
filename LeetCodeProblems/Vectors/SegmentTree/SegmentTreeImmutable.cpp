#include <vector>
using namespace std;

template <class T>
class SegmentTreeImmutable
{
public:
    SegmentTreeImmutable(vector<T>& arr)
    {
        sz = arr.size();
        resizeSegTree(sz);
        buildSegTree(arr,0,0,sz-1);
    }
    
    T query(T left, T right)
    {
        return querySegTree(0,0,sz-1,left,right);
    }
    
    void update(int arrIndex, T val)
    {
        updateValSegTree(0,0,sz-1,arrIndex,val);
    }
private:
    void resizeSegTree(int size)
    {
        int finalSize = 1;
        if(sz>1)
        {
            size--;
            int power=1;
            while(size>0)
            {
                size=size>>1;
                power++;
            }
            finalSize = pow(2,power)-1;
        }
        tree.resize(finalSize);
    }
    
    void buildSegTree(vector<T>& arr, int treeIndex, int lo, int hi)
    {
        if (lo == hi) {
            tree[treeIndex] = arr[lo];
            return;
        }

        int mid = lo + (hi - lo) / 2;
        buildSegTree(arr, 2 * treeIndex + 1, lo, mid);
        buildSegTree(arr, 2 * treeIndex + 2, mid + 1, hi);

        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
    
    int querySegTree(int treeIndex, int lo, int hi, int i, int j)
    {
        if (lo > j || hi < i) return 0; // segment completely outside range represents a null node
        if (i <= lo && j >= hi) return tree[treeIndex]; // segment completely inside range
        int mid = lo + (hi - lo) / 2; // partial overlap of current segment and queried range. Recurse deeper.

        if (i > mid) return querySegTree(2 * treeIndex + 2, mid + 1, hi, i, j);
        else if (j <= mid) return querySegTree(2 * treeIndex + 1, lo, mid, i, j);

        T leftQuery = querySegTree(2 * treeIndex + 1, lo, mid, i, mid);
        T rightQuery = querySegTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

        return leftQuery+rightQuery;
    }
    
    void updateValSegTree(int treeIndex, int lo, int hi, int arrIndex, T val)
    {
        if (lo == hi) {                 // leaf node. update element.
            tree[treeIndex] = val;
            return;
        }

        int mid = lo + (hi - lo) / 2;   // recurse deeper for appropriate child

        if (arrIndex > mid) updateValSegTree(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
        else if (arrIndex <= mid) updateValSegTree(2 * treeIndex + 1, lo, mid, arrIndex, val);
        
        tree[treeIndex] = tree[2 * treeIndex + 1] + tree[2 * treeIndex + 2];
    }
    
    vector<T> tree;
    int sz;
};