class UnionFind {
    vector<int> parent;
    int totalGroups;

    public:

    UnionFind(int capacity) {
        totalGroups = capacity;
        parent.resize(capacity);
        iota(parent.begin(), parent.end(), 0); // assign parent[i] = i
    }


    /**
     * Add Groups returns true after adding groups, or false when nodes are 
     * already part of same group
     */
    bool addGroups(int u, int v) {
        int parentU = findGroupParent(u);
        int parentV = findGroupParent(v);
        if (parentU == parentV) {
            // They are already in same group
            return false;
        }

        // Decrease group count
        totalGroups--;

        // Join the nodes
        parent[parentV] = parentU;
        return true;
    }

    // findGroupParent returns parent of node u with path compression
    int findGroupParent (int u) {
        if (parent[u] == u) {
            return u; // Found the parent
        }

        parent[u] = findGroupParent(parent[u]); // Path compression
        return parent[u];
    }

    int getGroups() {
        return this -> totalGroups;
    }
};

class Solution {


public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // We can find the total components by using union find
        UnionFind components(n);
        
        // Go through every edge and join the components.
        for (auto edge: edges) {
            components.addGroups(edge[0], edge[1]);
        }

        // return the result

        return components.getGroups();
    }
};
