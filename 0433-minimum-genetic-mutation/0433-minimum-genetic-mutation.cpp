class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> st(bank.begin(), bank.end());
        if (!st.count(endGene)) {
            return -1;
        }
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);
        string genes = "ACGT";
        while (!q.empty()) {
            string current = q.front().first;
            int steps = q.front().second;
            q.pop();
            if (current == endGene) {
                return steps;
            }
            for (int i = 0; i < current.size(); i++) {
                char old = current[i];
                for (char ch : genes) {
                    current[i] = ch;
                    if (st.count(current) && !visited.count(current)) {
                        visited.insert(current);
                        q.push({current, steps + 1});
                    }
                }
                current[i] = old;
            }
        }
        return -1;
    }
};