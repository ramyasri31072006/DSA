/*
===========================================================
🧠 INTUITION: Bellman-Ford Algorithm
===========================================================

The Bellman-Ford algorithm is used to find the shortest
distance from a source node to all other nodes in a graph.

🔹 Key Ideas:
1. A graph can have negative edge weights (unlike Dijkstra).
2. The shortest path can have at most (V-1) edges.
3. So, we relax all edges (V-1) times to ensure correctness.
4. After that, we do one more iteration:
   - If we can still relax an edge → Negative Cycle exists.

🔹 Why (V-1) times?
Because the longest possible simple path in a graph with V
vertices has (V-1) edges.

🔹 What is Relaxation?
If distance[u] + weight < distance[v],
we update distance[v].

🔹 Negative Cycle:
If distances keep decreasing even after (V-1) iterations,
it means there is a cycle with negative total weight.

Time Complexity: O(V * E)
Space Complexity: O(V)

===========================================================
*/

#include <bits/stdc++.h>   // Includes all standard libraries
using namespace std;       // Avoids writing std:: repeatedly

// Function to implement Bellman-Ford algorithm
vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    
    int n = edges.size();                 // Number of edges
    
    vector<int> dis(V, 1e8);              // Distance array initialized with large value (infinity)

    dis[src] = 0;                         // Distance from source to itself is 0

    // Step 1: Relax all edges (V-1) times
    for(int i = 0; i < V-1; i++){         // Repeat V-1 times
        for(int j = 0; j < n; j++){       // Loop through all edges
            
            int u = edges[j][0];          // Start node of edge
            int v = edges[j][1];          // End node of edge
            int w = edges[j][2];          // Weight of edge

            // Relaxation condition:
            // If distance to u is known and going through u improves v
            if(dis[u] != 1e8 && dis[u] + w < dis[v]){
                dis[v] = dis[u] + w;      // Update shortest distance to v
            }
        }
    }

    // Step 2: Check for negative weight cycle
    for(auto &edge : edges){              // Traverse all edges again
        
        int u = edge[0];                  // Start node
        int v = edge[1];                  // End node
        int w = edge[2];                  // Weight

        // If we can still relax → Negative cycle exists
        if(dis[u] != 1e8 && dis[u] + w < dis[v]){
            return {-1};                  // Return {-1} to indicate negative cycle
        }
    }

    return dis;                           // Return final shortest distances
}

int main() {
    
    int V, E;                             // V = number of vertices, E = number of edges
   
    cin >> V >> E;                        // Input vertices and edges

    vector<vector<int>> edges(E, vector<int>(3)); // Edge list: each edge has (u, v, w)

    // Input all edges
    for(int i = 0; i < E; i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    int src;                              // Source vertex
   
    cin >> src;                           // Input source

    vector<int> result = bellmanFord(V, edges, src); // Call Bellman-Ford

    // Check if negative cycle detected
    if(result.size() == 1 && result[0] == -1){
        cout << "Negative weight cycle detected\n";
    } 
    else {
        cout << "\nShortest distances from source:\n";
        
        // Print shortest distances to all vertices
        for(int i = 0; i < V; i++){
            cout << "Vertex " << i << " -> " << result[i] << endl;
        }
    }

    return 0;                            
}