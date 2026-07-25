class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        int l = s.length();
        return (s[l-1] - '0') * (s[l-2] - '0');
    }
};