class Solution {
public:
    pair<int, int> getPosition(int num, int n) {
        int row = n - 1 - (num - 1) / n;
        int col = (num - 1) % n;
        if ((n - row) % 2 == 0) {
            col = n - 1 - col;
        }
        return {row, col};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        queue<pair<int, int>> q;
        vector<bool> visited(n * n + 1, false);
        q.push({1, 0});
        visited[1] = true;
        while (!q.empty()) {
            int cell = q.front().first;
            int moves = q.front().second;
            q.pop();
            if (cell == n * n) {
                return moves;
            }
            for (int i = 1; i <= 6 && cell + i <= n * n; i++) {
                int next = cell + i;
                auto pos = getPosition(next, n);
                int row = pos.first;
                int col = pos.second;
                if (board[row][col] != -1) {
                    next = board[row][col];
                }
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};