class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& g, int k) {
        int m = g.size(), n = g[0].size(), total = m * n;
        vector<vector<int>> r(m, vector<int>(n));
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int oldIdx = i * n + j;
                int newIdx = (oldIdx + k) % total;
                r[newIdx / n][newIdx % n] = g[i][j];
            }
        }
        
        return r;
    }
};