class NumArray {
public:
    vector<int> arr;
    vector<int> seg;
    int n;
    void build(int idx, int low, int high) {
        if (low == high) {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low+high)/2;
        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        if (low >= l && high <= r) {
            return seg[idx];
        }
        if (high < l || low > r) {
            return 0;
        }
        int mid = low + (high - low) / 2;
        int leftSum = query(2 * idx + 1, low, mid, l, r);
        int rightSum = query(2 * idx + 2, mid + 1, high, l, r);
        return leftSum + rightSum;
    }

    void update(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }
        int mid = low + (high - low) / 2;
        if (pos <= mid) {
            update(2 * idx + 1, low, mid, pos, val);
        } else {
            update(2 * idx + 2, mid + 1, high, pos, val);
        }
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();
        seg.resize(4 * n);
        if (n > 0) {
            build(0, 0, n - 1);
        }
    }
    void update(int index, int val) { update(0, 0, n - 1, index, val); }
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */