#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> count;
        for (int num : nums) {
            count[num]++;
        }
        int max_len = 1;
        if (count.count(1)) {
            int ones = count[1];
            if (ones % 2 == 0) {
                ones -= 1;
            }
            max_len = max(max_len, ones);
        }

        for (auto const& [x, freq] : count) {
            if (x == 1) continue; 
            
            long long curr = x;
            int length = 0;
            while (count.count(curr) && count[curr] >= 2) {
                length += 2;
                curr = curr * curr;
            }
            
            if (count.count(curr) && count[curr] > 0) {
                length += 1; 
            } else {
                length -= 1;
            }
            
            max_len = max(max_len, length);
        }
        
        return max_len;
    }
};