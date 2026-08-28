class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int odd = 0;
        char middle = 0;
        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }
        if (odd > 1) return "";
        vector<int> halfCnt(26);
        int m = n / 2;
        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }
        string left = "";
        vector<int> remaining = halfCnt;
        int i = 0;
        for (; i < m; i++) {
            int x = target[i] - 'a';
            if (remaining[x] > 0) {
                left += target[i];
                remaining[x]--;
            } else {
                break;
            }
        }
        auto build = [&](string h) {
            string ans = h;
            if (n % 2 == 1) {
                ans += middle;
            }
            string rev = h;
            reverse(rev.begin(), rev.end());

            return ans + rev;
        };
        if (i == m) {
            string candidate = build(left);
            if (candidate > target) {
                return candidate;
            }
        }
        for (int pos = min(i, m - 1); pos >= 0; pos--) {
            if (pos < (int)left.size()) {
                remaining[left.back() - 'a']++;
                left.pop_back();
            }
            int current = target[pos] - 'a';
            for (int c = current + 1; c < 26; c++) {
                if (remaining[c] > 0) {
                    string candidateLeft = left;
                    remaining[c]--;
                    candidateLeft += char('a' + c);
                    for (int k = 0; k < 26; k++) {
                        candidateLeft.append(
                            remaining[k],
                            char('a' + k)
                        );
                    }
                    string answer = build(candidateLeft);
                    if (answer > target) {
                        return answer;
                    }
                    remaining[c]++;
                }
            }
        }
        return "";
    }
};