class Solution {
public:
    string smallestPalindrome(string s) {
        int freq[26] = {};
        for (char c : s) {
            freq[c - 'a']++;
        }
        string left = "";
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < freq[i] / 2; j++) {
                left += char('a' + i);
            }
        }
        string right = left;
        reverse(right.begin(), right.end());
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1) {
                middle += char('a' + i);
                break;
            }
        }
        return left + middle + right;
    }
};