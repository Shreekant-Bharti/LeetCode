class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = 0;
        for (int x : nums) {
            mx = max(mx, x);
        }
        
        vector<int> cnt(mx + 1, 0);
        for (int x : nums) {
            cnt[x]++;
        }
        
        vector<long long> f(mx + 1, 0);
        vector<long long> g(mx + 1, 0);
        
        for (int i = 1; i <= mx; i++) {
            long long c = 0;
            for (int j = i; j <= mx; j += i) {
                c += cnt[j];
            }
            f[i] = c * (c - 1) / 2;
        }
        
        for (int i = mx; i >= 1; i--) {
            g[i] = f[i];
            for (int j = 2 * i; j <= mx; j += i) {
                g[i] -= g[j];
            }
        }
        
        vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++) {
            pref[i] = pref[i - 1] + g[i];
        }
        
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            long long target = queries[i] + 1;
            int idx = lower_bound(pref.begin(), pref.end(), target) - pref.begin();
            ans[i] = idx;
        }
        
        return ans;
    }
};