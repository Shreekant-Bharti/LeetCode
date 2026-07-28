class Solution {
public:
    string smallestPalindrome(string s) {
        int f[26] = {0};
        for (char c : s) f[c - 'a']++;
        string h = "", m = "";
        for (int i = 0; i < 26; i++) {
            if (f[i] % 2) m = string(1, 'a' + i);
            h += string(f[i] / 2, 'a' + i);
        }
        string r = h;
        reverse(r.begin(), r.end());
        return h + m + r;
    }
};