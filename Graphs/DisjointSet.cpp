#include <bits/stdc++.h>  
using namespace std;

/*
====================================================================
🔹 DISJOINT SET UNION (DSU) / UNION-FIND

Definition:
Disjoint Set Union (DSU) is a data structure used to manage a 
collection of non-overlapping (disjoint) sets efficiently.

Main Operations:
1️⃣ Find(x)  → Returns the ultimate parent (representative) of x.
2️⃣ Union(u, v) → Merges the sets containing u and v.

Optimizations:
✅ Path Compression → Flattens the tree during Find.
✅ Union by Rank → Attaches smaller tree under larger tree.

Time Complexity:
Nearly O(1) per operation (O(α(n)) - Inverse Ackermann Function)
====================================================================
*/

class DisjointSet {

    vector<int> Rank;     // Stores rank (approximate tree height)
    vector<int> parent;   // Stores parent of each node

public:

    // Constructor: Initializes DSU with n elements (0 to n)
    DisjointSet(int n) {

        Rank.resize(n + 1, 0);   // Initialize all ranks to 0
        parent.resize(n + 1);    // Allocate parent array

        // Initially, every node is its own parent
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // 🔹 Find with Path Compression
    // Returns ultimate parent of the node
    int findUpar(int node) {

        // If node is root, return it
        if (node == parent[node])
            return node;

        // Path Compression:
        // Attach node directly to ultimate parent
        return parent[node] = findUpar(parent[node]);
    }

    // 🔹 Union by Rank
    // Merges two sets based on rank
    void UnionByRank(int u, int v) {

        // Find ultimate parents
        int ulpu = findUpar(u);
        int ulpv = findUpar(v);

        // If both nodes are already in same set
        if (ulpu == ulpv)
            return;

        // Attach smaller rank tree under larger rank tree
        if (Rank[ulpu] > Rank[ulpv]) {
            parent[ulpv] = ulpu;
        }
        else if (Rank[ulpv] > Rank[ulpu]) {
            parent[ulpu] = ulpv;
        }
        else {
            parent[ulpv] = ulpu;
            Rank[ulpu]++;   // Increase rank when ranks are equal
        }
    }
};

int main() {

    DisjointSet ds(7);  // Create DSU with 7 nodes (1 to 7)

    // Perform union operations
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);

    // Check if nodes 3 and 7 belong to same component
    if (ds.findUpar(3) == ds.findUpar(7))
        cout << "Same Component\n";
    else
        cout << "Different Component\n";

    // Merge components of 3 and 7
    ds.UnionByRank(3, 7);

    // Check again after merging
    if (ds.findUpar(3) == ds.findUpar(7))
        cout << "Same Component\n";
    else
        cout << "Different Component\n";

    return 0;   // End of program

}
