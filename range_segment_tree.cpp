// lazy prop segment tree range updates and query
class SegmentTree{
    public:
    vector<long long> tree, lazy;
    SegmentTree(int n){
        tree.resize(4*n+1, 0);
        lazy.resize(4*n+1, 0);
    }
    void build(int ind, int l, int r, vector<long long> &v){
        if(l == r){
            tree[ind] = v[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*ind+1, l, mid, v);
        build(2*ind+2, mid+1, r, v);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
    long long rangeSum(int ind, int l, int r, int i, int j){
        // i and j are range in which you want the sum
        tree[ind] = tree[ind] + (r - l + 1) * lazy[ind];
        if(l != r){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
        if(i <= l && r <= j){
            return tree[ind];
        }
        if(r < i || l > j) {
            return 0;
        }
        int mid = (l + r) / 2;
        long long left = rangeSum(2*ind+1, l, mid, i, j);
        long long right = rangeSum(2*ind+2, mid+1, r, i, j);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
        return left + right;
    }
    void rangeUpdate(int ind, int l, int r, int i, int j, int val){
        tree[ind] = tree[ind] + (r - l + 1) * lazy[ind];
        if(l != r){
            lazy[2*ind+1] += lazy[ind];
            lazy[2*ind+2] += lazy[ind];
        }
        lazy[ind] = 0;
        if(i <= l && r <= j){
            tree[ind] = tree[ind] + (r - l + 1) * val;
            if(l != r){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            return;
        }
        if(r < i || l > j) {
            return;
        }
        int mid = (l + r) / 2;
        rangeUpdate(2*ind+1, l, mid, i, j, val);
        rangeUpdate(2*ind+2, mid+1, r, i, j, val);
        tree[ind] = tree[2*ind+1] + tree[2*ind+2];
    }
};
// How to use
// SegmentTree st(N);
// st.build(1,0,N-1,v)
// st.rangeUpdate(1, 0, N-1, LQ, RQ, value) : (LQ,RQ - update range inc - 0 Indexing)
// st.rangeSum(1, 0, N-1, LQ, RQ) : (LQ,RQ - query range inc - 0 Indexing)