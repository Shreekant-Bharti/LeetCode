class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Array to store the frequency of each character in the alphabet
        vector<int> count(26, 0);
        
        // Count frequencies of all characters in the text
        for (char c : text) {
            count[c - 'a']++;
        }
        
        // Calculate the minimum instances we can form
        // 'l' and 'o' require 2 characters per word, so we divide their counts by 2
        return min({
            count['b' - 'a'], 
            count['a' - 'a'], 
            count['l' - 'a'] / 2, 
            count['o' - 'a'] / 2, 
            count['n' - 'a']
        });
    }
};