#include<bits/stdc++.h>

class Solution {
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        std::vector<int> bit(2 * n + 2, 0);
        auto add = [&](int idx, int val) {
            for (; idx < bit.size(); idx += idx & -idx) {
                bit[idx] += val;
            }
        };
        auto query = [&](int idx) {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx) {
                sum += bit[idx];
            }
            return sum;
        };

        long long ans = 0;
        int current_pref = 0;
        add(0 + n + 1, 1);

        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                current_pref += 1;
            } else {
                current_pref -= 1;
            }
            ans += query(current_pref + n);
            add(current_pref + n + 1, 1);
        }

        return ans;
    }
};