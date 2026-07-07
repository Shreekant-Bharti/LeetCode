class Solution {
public:
    long long sumAndMultiply(int n) {
        string s = to_string(n), r = "";
        long long sm = 0;
        
        for (char c : s) {
            if (c != '0') {
                r += c;
                sm += c - '0';
            }
        }
        
        if (r.empty()) return 0;
        
        return stoll(r) * sm;
    }
};