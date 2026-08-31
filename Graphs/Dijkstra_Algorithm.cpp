// Purpose: Find the shortest path distances from a single source vertex to all other vertices
//          in a graph with non-negative edge weights.

// Input: A weighted graph (usually represented by edges or adjacency list) and a source vertex.

// Output: A list of shortest distances from the source to every other vertex.

// User Function Template
class Solution {
  private:
   // Helper function to perform Dijkstra's algorithm to find shortest paths
   void shortPath(int src, vector<vector<pair<int,int>>>& adj, vector<int>& dis) {
       
       // Min-heap (priority queue) to pick the vertex with the smallest distance
       // Each element is a pair: {distance, vertex}
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
       
       // Distance from source to itself is always zero
       dis[src] = 0;
       pq.push({0, src});  // Push the source vertex into the priority queue
       
       while (!pq.empty()) {
           // Extract vertex with the smallest tentative distance
           auto idx = pq.top();
           pq.pop();
           
           // idx.first = current distance to this vertex
           // idx.second = vertex number
           
           // Explore all neighbors of the current vertex
           for (auto i : adj[idx.second]) {
               // i.first = neighbor vertex
               // i.second = edge weight to neighbor
               
               // If the path through current vertex offers a shorter path to neighbor
               if (idx.first + i.second < dis[i.first]) {
                   
                   // Update distance to the neighbor
                   dis[i.first] = idx.first + i.second;
                   
                   // Push the updated distance and vertex into the priority queue
                   pq.push({dis[i.first], i.first});
               }
           }
       }
   }
  
  public:
    vector<int> dijkstra(int V, vector<vector<int>>& edges, int src) {
        // Initialize distance vector with infinity (INT_MAX)
        vector<int> dis(V, INT_MAX);
        int n = edges.size();
        
        // Build adjacency list from edge list
        // adj[u] stores pairs {v, weight} for edges u -> v
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < n; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            // Since the graph is undirected, add edge both ways
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        // Run Dijkstra's algorithm from source node to compute shortest paths
        shortPath(src, adj, dis);
        
        // Return the distances from source to all vertices
        return dis;
    }
};
