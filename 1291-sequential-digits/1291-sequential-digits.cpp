class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s = "123456789";
        int nl = to_string(low).length();
        int nh = to_string(high).length();
        
        for (int l = nl; l <= nh; ++l) {
            for (int i = 0; i <= 9 - l; ++i) {
                int v = stoi(s.substr(i, l));
                if (v >= low && v <= high) {
                    res.push_back(v);
                }
            }
        }
        return res;
    }
};