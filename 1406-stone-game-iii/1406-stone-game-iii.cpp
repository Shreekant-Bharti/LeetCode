class Solution {
public:
    string stoneGameIII(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            int res = INT_MIN, sum = 0;
            for (int k = 0; k < 3 && i + k < n; k++) {
                sum += v[i + k];
                res = max(res, sum - dp[i + k + 1]);
            }
            dp[i] = res;
        }
        
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};