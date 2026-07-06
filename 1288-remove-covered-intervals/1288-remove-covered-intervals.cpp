class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& A) {
        sort(A.begin(), A.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        });
        
        int c = 0;
        int e = -1;
        
        for (auto& i : A) {
            if (i[1] > e) {
                c++;
                e = i[1];
            }
        }
        
        return c;
    }
};