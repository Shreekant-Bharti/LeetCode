class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        
        vector<bool> vis(26, false);
        string res = "";
        
        for (char c : s) {
            cnt[c - 'a']--;
            if (vis[c - 'a']) continue;
            
            while (!res.empty() && res.back() > c && cnt[res.back() - 'a'] > 0) {
                vis[res.back() - 'a'] = false;
                res.pop_back();
            }
            
            res.push_back(c);
            vis[c - 'a'] = true;
        }
        return res;
    }
};