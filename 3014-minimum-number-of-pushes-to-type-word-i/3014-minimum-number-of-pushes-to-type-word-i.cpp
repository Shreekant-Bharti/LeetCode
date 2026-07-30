class Solution {
public:
    int minimumPushes(string w) {
        int n = w.size(), ans = 0, p = 1;
        while (n > 0) {
            int k = min(n, 8);
            ans += k * p;
            n -= k;
            p++;
        }
        return ans;
    }
};