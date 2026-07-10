#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& a, int mx, vector<vector<int>>& q) {
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {a[i], i};
        }
        sort(v.begin(), v.end());
        
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[v[i].second] = i;
        }
        
        vector<vector<int>> up(18, vector<int>(n));
        for (int i = 0, j = 0; i < n; ++i) {
            while (j + 1 < n && v[j + 1].first - v[i].first <= mx) {
                j++;
            }
            up[0][i] = j;
        }
        
        for (int j = 1; j < 18; ++j) {
            for (int i = 0; i < n; ++i) {
                up[j][i] = up[j - 1][up[j - 1][i]];
            }
        }
        
        vector<int> res;
        res.reserve(q.size());
        for (auto& qr : q) {
            int x = p[qr[0]];
            int y = p[qr[1]];
            
            if (x == y) {
                res.push_back(0);
                continue;
            }
            
            if (x > y) {
                swap(x, y);
            }
            
            if (up[17][x] < y) {
                res.push_back(-1);
                continue;
            }
            
            int ans = 0;
            for (int j = 17; j >= 0; --j) {
                if (up[j][x] < y) {
                    ans += (1 << j);
                    x = up[j][x];
                }
            }
            res.push_back(ans + 1);
        }
        
        return res;
    }
};