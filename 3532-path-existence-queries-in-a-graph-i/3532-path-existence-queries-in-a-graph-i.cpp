#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> c(n, 0);
        for (int i = 1; i < n; ++i) {
            c[i] = c[i - 1] + (nums[i] - nums[i - 1] > maxDiff);
        }
        
        int q = queries.size();
        vector<bool> r(q);
        for (int i = 0; i < q; ++i) {
            r[i] = (c[queries[i][0]] == c[queries[i][1]]);
        }
        
        return r;
    }
};