class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int freq[26] = {0};

        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (freq[target[i] - 'a'] > 0) {
                ans += target[i];
                freq[target[i] - 'a']--;
            } 
            else {
                for (int c = target[i] - 'a' + 1; c < 26; c++) {
                    if (freq[c] > 0) {
                        ans += char('a' + c);
                        freq[c]--;

                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }

                break;
            }
        }

        // Backtrack
        for (int i = ans.size() - 1; i >= 0; i--) {
            freq[ans[i] - 'a']++;

            for (int c = ans[i] - 'a' + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string result = ans.substr(0, i);
                    result += char('a' + c);
                    freq[c]--;

                    for (int j = 0; j < 26; j++) {
                        result += string(freq[j], char('a' + j));
                    }

                    return result;
                }
            }
        }

        return "";
    }
};