class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
        vector<vector<long long>> open(n + 1, vector<long long>(k + 1));
        dp[1][0] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = (dp[i - 1][j] + open[i - 1][j]) % MOD;
                if (j > 0) {
                    open[i][j] = (open[i - 1][j] +
                                  dp[i - 1][j - 1] +
                                  open[i - 1][j - 1]) % MOD;
                }
            }
        }
        return (dp[n][k] + open[n][k]) % MOD;
    }
};