class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // for a valid tree on n nodes, it should have n - 1 edges and 
        // all of them should be connected.


        // Base case: if number of edges is not n - 1
        if (edges.size() != n - 1) {
            return false;
        }

        // We can do DFS using stack to make sure all the edges are connected
        stack<int> st;
        vector<vector<int>> adj(n, vector<int>());
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        st.push(0);
        while (!st.empty()) {
            int curr = st.top(); st.pop();

            for (auto neighbor: adj[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    st.push(neighbor);
                }
            }
        }

        for (auto isVisited: visited) {
            if (!isVisited) {
                return false;
            }
        }
        return true;
    }
};
