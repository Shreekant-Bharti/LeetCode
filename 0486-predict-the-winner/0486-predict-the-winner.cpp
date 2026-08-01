class Solution {
public:
    bool predictTheWinner(vector<int>& v) {
        int n = v.size();
        int a[20] = {0};

        for (int i = 0; i < n; i++) {
            a[i] = v[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                a[j] = max(v[i] - a[j], v[j] - a[j - 1]);
            }
        }

        return a[n - 1] >= 0;
    }
};