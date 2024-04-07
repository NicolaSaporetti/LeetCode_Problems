template <class T>
class SegmentTree
{
public:
    SegmentTree(vector<T>& nums) : size(nums.size()), vec(getSegmentTreeSize(nums.size()-1))
    {
        build(nums, 1, 0, nums.size()-1);
    }
    T sum(int left, int right)
    {
        return sum(1,0,size-1,left,right);
    }
    
    void update(int pos, T new_val)
    {
        update(1,0,size-1,pos,new_val);
    }
private:
    int getSegmentTreeSize(int size)
    {
        int power = 1;
        while(size>0)
        {
            size=size>>1;
            power++;
        }
        return pow(2,power);
    }
    void build(vector<int>& nums, int v, int tl, int tr) {
        if (tl == tr) {
            vec[v] = nums[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(nums, v*2, tl, tm);
            build(nums, v*2+1, tm+1, tr);
            vec[v] = vec[v*2] + vec[v*2+1];
        }
    }
    T sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return vec[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
            + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            vec[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            vec[v] = vec[v*2] + vec[v*2+1];
        }
    }
    vector<T> vec;
    int size;
};