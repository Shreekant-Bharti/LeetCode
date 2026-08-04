class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        auto [b, c] = minmax_element(a.begin(), a.end());
        unordered_set<int> s(a.begin(), a.end());
        vector<int> d;
        for (int i = *b; i <= *c; i++) {
            if (!s.count(i)) d.push_back(i);
        }
        return d;
    }
};