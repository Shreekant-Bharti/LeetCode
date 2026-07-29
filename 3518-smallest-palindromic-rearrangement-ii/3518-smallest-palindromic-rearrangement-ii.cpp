class Solution {
    long long cb(int n, int r, long long cap) {
        if (r < 0 || r > n) return 0;
        if (r == 0 || r == n) return 1;
        if (r > n - r) r = n - r;
        long long res = 1;
        for (int i = 1; i <= r; ++i) {
            res = res * (n - r + i) / i;
            if (res > cap) return cap;
        }
        return res;
    }

    long long wy(const vector<int>& c, int t, long long cap) {
        long long w = 1;
        int rm = t;
        for (int x : c) {
            if (x == 0) continue;
            w = w * cb(rm, x, cap);
            if (w > cap) w = cap;
            rm -= x;
        }
        return w;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.length();
        int m = n / 2;
        vector<int> f(26, 0), c(26, 0);
        for (char x : s) f[x - 'a']++;
        for (int i = 0; i < 26; ++i) c[i] = f[i] / 2;
        
        char md = 0;
        if (n % 2 != 0) {
            for (int i = 0; i < 26; ++i) {
                if (f[i] % 2 != 0) {
                    md = 'a' + i;
                    break;
                }
            }
        }

        string p = "";
        long long cur_k = k;
        for (int i = 0; i < m; ++i) {
            bool ok = false;
            for (int j = 0; j < 26; ++j) {
                if (c[j] == 0) continue;
                c[j]--;
                long long w = wy(c, m - 1 - i, cur_k + 1);
                if (w >= cur_k) {
                    p += (char)('a' + j);
                    ok = true;
                    break;
                }
                cur_k -= w;
                c[j]++;
            }
            if (!ok) return "";
        }

        string ans = p;
        if (n % 2 != 0) ans += md;
        string rev = p;
        reverse(rev.begin(), rev.end());
        ans += rev;
        return ans;
    }
};