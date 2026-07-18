class Solution {
public:
    int findGCD(vector<int>& num) {
        auto [a, b] = minmax_element(num.begin(), num.end());
        return gcd(*a, *b);        
    }
};