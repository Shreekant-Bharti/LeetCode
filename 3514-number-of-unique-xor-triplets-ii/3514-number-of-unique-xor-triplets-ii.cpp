class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> u(nums.begin(), nums.end());
        vector<int> a(u.begin(), u.end());
        int n = a.size();
        
        vector<bool> p(2048, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                p[a[i] ^ a[j]] = true;
            }
        }
        
        vector<bool> ans(2048, false);
        for (int x = 0; x < 2048; ++x) {
            if (!p[x]) continue;
            for (int y : a) {
                ans[x ^ y] = true;
            }
        }
        
        int c = 0;
        for (bool b : ans) {
            if (b) c++;
        }
        return c;
    }
};