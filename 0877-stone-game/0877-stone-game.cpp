class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int n = p.size();
        int d[505][505] = {0};
        for (int i = 0; i < n; i++) d[i][i] = p[i];
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                d[i][j] = max(p[i] - d[i + 1][j], p[j] - d[i][j - 1]);
            }
        }
        return d[0][n - 1] > 0;
    }
};