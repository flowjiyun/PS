class Solution {
public:
    set<vector<int>> routes;
    vector<int> visited;
    unordered_map<int, vector<int>> graph;

    int minReorder(int n, vector<vector<int>>& connection){
        visited = vector(n, 0);
        for (auto way : connection) {
            int node = way[0];
            int nei = way[1];
            graph[node].push_back(nei);
            graph[nei].push_back(node);
            routes.insert({node, nei});
        }

        visited[0] = 1;
        return dfs(0);
    }

    int dfs(int curNodeIndex) {
        int ans = 0;
        for (auto neighbor : graph[curNodeIndex]) {
            if (visited[neighbor] == 1) {
                continue;
            }
            if (routes.find({curNodeIndex, neighbor}) != routes.end()) {
                ++ans;
            }
            visited[neighbor] = 1;
            ans += dfs(neighbor);
        }
        return ans;
    }
};