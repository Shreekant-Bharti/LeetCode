#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int m = 1e9 + 7;
        int n = s.size();
        vector<int> val;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') {
                val.push_back(s[i] - '0');
            }
        }
        
        int k = val.size();
        vector<int> nxt(n, -1), prv(n, -1);
        int c = -1;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != '0') c++;
            prv[i] = c;
        }
        
        c = k;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] != '0') c--;
            if (c < k) nxt[i] = c;
        }

        vector<long long> p(k + 1, 0), v(k + 1, 0), p10(k + 1, 1);
        
        for (int i = 0; i < k; ++i) {
            p[i + 1] = p[i] + val[i];
            v[i + 1] = (v[i] * 10 + val[i]) % m;
            p10[i + 1] = (p10[i] * 10) % m;
        }

        vector<int> res;
        
        for (auto& a : q) {
            int l = a[0], r = a[1];
            int L = nxt[l], R = prv[r];
            
            if (L == -1 || R == -1 || L > R) {
                res.push_back(0);
                continue;
            }
            
            long long sum = p[R + 1] - p[L];
            long long len = R - L + 1;
            long long x = (v[R + 1] - (v[L] * p10[len]) % m + m) % m;
            
            res.push_back((x * (sum % m)) % m);
        }
        
        return res;
    }
};