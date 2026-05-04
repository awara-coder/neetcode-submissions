class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        /* For a valid tree:
        1. All nodes must be connected
        2. There are exactly n - 1 edges for n nodes.
        We can start BFS and make sure everything is connected.
        Let's not do DFS to prevent stack overflow.
        */

        // make sure there are only n - 1 edges
        if ((int)edges.size() != n - 1) {
            return false;
        }

        // Create adjacency graph
        vector<vector<int>> adjGraph(n);
        for (const auto& edge: edges) {
            adjGraph[edge[0]].push_back(edge[1]);
            adjGraph[edge[1]].push_back(edge[0]);
        }

        // Start a BFS with node 0 and make sure everything is connected.
        int visitedCount = 1;
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> toVisit;
        toVisit.push(0);
        while (!toVisit.empty()) {
            auto node = toVisit.front(); toVisit.pop();

            // Checkout all the nodes connect to this node via edges
            for (auto neighbor : adjGraph[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    toVisit.push(neighbor);
                    visitedCount++;
                }
            }
        }

        // Check if all nodes are reachable
        return visitedCount == n;
    }

};
