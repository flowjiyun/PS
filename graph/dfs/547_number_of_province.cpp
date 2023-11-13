class Solution {
public:
    unordered_map<int, vector<int>> edges;
    vector<bool> visited;
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        visited = vector(n, false);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    edges[i].push_back(j);
                    // edges[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                ++ans;
                visited[i] = true;
                dfs(i);
            }
        }
        return ans;
    }

    void dfs(int index) {
        for (auto node : edges[index]) {
            if (visited[node] == false) {
                visited[node] = true;
                dfs(node);
            }
        }
    }
};