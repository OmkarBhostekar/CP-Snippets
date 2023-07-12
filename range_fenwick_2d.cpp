struct FenwickTree2D {
    int n, m;
    vector<vector<int>> bit;

    FenwickTree2D(vector<vector<int>> &a) 
    : n(size(a)), m(size(a[0])), bit(n + 1, vector<int>(m + 1)) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                upd(i, j, a[i][j]);
            }
        }
    }

    // Add x at pos (r, c)
    void upd(int r, int c, int x) {
        for (int i = r + 1; i <= n; i += i & -i) {
            for (int j = c + 1; j <= m; j += j & -j) {
                bit[i][j] += x;
            }
        }
    }

    int sum(int r, int c) {
        int s = 0;
        for (int i = r + 1; i > 0; i -= i & -i) {
            for (int j = c + 1; j > 0; j -= j & -j) {
                s += bit[i][j];
            }
        }
        return s;
    }

    int query(int r1, int c1, int r2, int c2) {
        return sum(r2, c2) - sum(r1 - 1, c2) - sum(r2, c1 - 1) + sum(r1 - 1, c1 - 1);
    }
};
// how to use -> FenwickTree2D ft2d(v);
// ft2d.upd(r,c,val) -> 0 indexing
// ft2d.query(r1,c1,r2,c2) -> 0 indexing