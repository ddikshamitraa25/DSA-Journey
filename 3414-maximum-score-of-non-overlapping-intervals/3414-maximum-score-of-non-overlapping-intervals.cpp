class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long, 4>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }
        sort(a.begin(), a.end());
        vector<long long> starts(n);
        for (int i = 0; i < n; i++) {
            starts[i] = a[i][0];
        }
        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1,
            vector<pair<long long, vector<int>>>(5)
        );
        for (int i = n - 1; i >= 0; i--) {
            int next = upper_bound(
                starts.begin() + i + 1,
                starts.end(),
                a[i][1]
            ) - starts.begin();
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];
                long long score =
                    a[i][2] + dp[next][k - 1].first;
                vector<int> indices;
                indices.push_back(a[i][3]);
                for (int x : dp[next][k - 1].second) {
                    indices.push_back(x);
                }
                sort(indices.begin(), indices.end());
                if (score > dp[i][k].first ||
                    (score == dp[i][k].first &&
                     indices < dp[i][k].second)) {
                    dp[i][k] = {score, indices};
                }
            }
        }
        return dp[0][4].second;
    }
};