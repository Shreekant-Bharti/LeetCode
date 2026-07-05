class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& b) {
        int n = b.size(), m = 1e9 + 7;
        vector<vector<int>> d(n + 1, vector<int>(n + 1, -1));
        vector<vector<int>> c(n + 1, vector<int>(n + 1, 0));
        
        b[0][0] = b[n - 1][n - 1] = '0';
        d[n - 1][n - 1] = 0;
        c[n - 1][n - 1] = 1;
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (b[i][j] == 'X' || (i == n - 1 && j == n - 1)) continue;
                
                int mx = max({d[i + 1][j], d[i][j + 1], d[i + 1][j + 1]});
                if (mx == -1) continue;
                
                d[i][j] = mx + b[i][j] - '0';
                
                if (d[i + 1][j] == mx) c[i][j] = (c[i][j] + c[i + 1][j]) % m;
                if (d[i][j + 1] == mx) c[i][j] = (c[i][j] + c[i][j + 1]) % m;
                if (d[i + 1][j + 1] == mx) c[i][j] = (c[i][j] + c[i + 1][j + 1]) % m;
            }
        }
        
        return {c[0][0] ? d[0][0] : 0, c[0][0]};
    }
};