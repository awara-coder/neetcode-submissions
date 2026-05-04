class UnionFind {
    int capacity;
    vector<int> parent;
    vector<int> size;

    public:

    UnionFind(int capacity) : capacity(capacity) {
        parent.resize(capacity);
        iota(parent.begin(), parent.end(), 0);
        size.assign(capacity, 1);
    }

    // Returns parent of the set. 
    int find(int n) {
        if (parent[n] == n) {
            return n;
        }

        // Path compression
        return parent[n] = find(parent[n]);
    }

    // Unions to elements of set
    bool add(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if (parent[u] == parent[v]) {
            return false;
        }

        // Do the union
        if (size[parentV] > size[parentU]) {
            swap(parentU, parentV);
        }

        // Add the size
        size[parentU] += size[parentV];
        // re-assign parent
        parent[parentV] = parentU;

        return true;
    }

    // Function to find total number of sets
    int getSetCount() {
        int setCount = 0;
        for (int i = 0;i < capacity; i++) {
            if (parent[i] == i) {
                setCount++;
            }
        }

        return setCount;
    }
};

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        // There are multiple ways to solve this:
        // using BFS, DFS, but we are going to choose union find because we won't need
        // to build adjacency list graph for it.

        UnionFind disjointSet(n);

        for (auto edge: edges) {
            disjointSet.add(edge[0], edge[1]);
        }

        return disjointSet.getSetCount();
        
    }
};
