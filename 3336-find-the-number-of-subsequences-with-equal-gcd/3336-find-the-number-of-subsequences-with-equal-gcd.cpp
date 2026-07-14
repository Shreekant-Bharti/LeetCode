class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int m = 0;
        for (int x : nums) m = max(m, x);
        
        long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(m + 1, vector<long long>(m + 1, 0));
        dp[0][0] = 1;
        
        for (int x : nums) {
            vector<vector<long long>> next_dp = dp;
            for (int g1 = 0; g1 <= m; ++g1) {
                for (int g2 = 0; g2 <= m; ++g2) {
                    if (!dp[g1][g2]) continue;
                    
                    int ng1 = (g1 == 0) ? x : __gcd(g1, x);
                    next_dp[ng1][g2] = (next_dp[ng1][g2] + dp[g1][g2]) % MOD;
                    
                    int ng2 = (g2 == 0) ? x : __gcd(g2, x);
                    next_dp[g1][ng2] = (next_dp[g1][ng2] + dp[g1][g2]) % MOD;
                }
            }
            dp = move(next_dp);
        }
        
        long long ans = 0;
        for (int g = 1; g <= m; ++g) {
            ans = (ans + dp[g][g]) % MOD;
        }
        
        return ans;
    }
};