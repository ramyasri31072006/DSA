class Solution {
  public:
    bool bfs(int V, vector<vector<int>> &edges) {
        // Create adjacency list
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS traversal from node 0
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;

        while(!q.empty()) { // display each vertix from queue until queue is empty
            int idx = q.front();
            cout << idx << "\n";
            q.pop();

            for(auto i : adj[idx]) {//add the neighbhours of a node to queue if it is unvisited 
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        return true;
    }
};


