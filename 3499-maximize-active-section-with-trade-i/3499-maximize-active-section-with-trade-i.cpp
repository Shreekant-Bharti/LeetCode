class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int o = 0;
        for (char c : s) {
            if (c == '1') o++;
        }

        vector<pair<char, int>> g;
        for (int i = 0; i < n;) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            g.push_back({s[i], j - i});
            i = j;
        }

        int d = 0;
        int m = g.size();
        for (int i = 1; i < m - 1; i++) {
            if (g[i].first == '1' && g[i - 1].first == '0' && g[i + 1].first == '0') {
                d = max(d, g[i - 1].second + g[i + 1].second);
            }
        }

        return o + d;
    }
};