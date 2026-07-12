class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> t = arr;
        sort(t.begin(), t.end());
        t.erase(unique(t.begin(), t.end()), t.end());
        
        unordered_map<int, int> m;
        for (int i = 0; i < t.size(); ++i) {
            m[t[i]] = i + 1;
        }
        
        vector<int> r(arr.size());
        for (int i = 0; i < arr.size(); ++i) {
            r[i] = m[arr[i]];
        }
        
        return r;
    }
};