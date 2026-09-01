class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<pair<int, int>> litter;
        int sr = 0, sc = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }
                if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }
        int k = litter.size();
        if (k == 0)
            return 0;
        int allMask = (1 << k) - 1;
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        for (int i = 0; i < k; i++) {
            int r = litter[i].first;
            int c = litter[i].second;
            litterId[r][c] = i;
        }
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(1 << k, false)
                )
            )
        );
        queue<tuple<int, int, int, int, int>> q;
        q.push({sr, sc, energy, 0, 0});
        visited[sr][sc][energy][0] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [r, c, currEnergy, mask, moves] = q.front();
            q.pop();
            if (mask == allMask)
                return moves;
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;
                if (classroom[nr][nc] == 'X')
                    continue;
                if (currEnergy == 0)
                    continue;
                int newEnergy = currEnergy - 1;
                if (classroom[nr][nc] == 'R') {
                    newEnergy = energy;
                }
                int newMask = mask;
                if (classroom[nr][nc] == 'L') {
                    int id = litterId[nr][nc];
                    newMask |= (1 << id);
                }
                if (!visited[nr][nc][newEnergy][newMask]) {
                    visited[nr][nc][newEnergy][newMask] = true;
                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask,
                        moves + 1
                    });
                }
            }
        }
        return -1;
    }
};