// Given a starting pixel, the algorithm changes the color of that pixel and 
//all adjacent pixels that have the same original color to a new color.
// It continues this process recursively or iteratively, spreading out to all 
//connected pixels with the same original color.

class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Store the original color of the starting pixel
        int intial = image[sr][sc];
        // Get the number of rows (n) and columns (m) in the image
        int n = image.size();
        int m = image[0].size();
        // Create a reference to the image to modify it directly
        vector<vector<int>>& c = image;
        
        // Queue to hold the pixels to be processed for flood fill (BFS)
        queue<pair<int,int>> q;
        
        // Start BFS from the starting pixel (sr, sc)
        q.push({sr, sc});
        
        // Change the color of the starting pixel to newColor
        c[sr][sc] = newColor;
        
        // Arrays to help explore 4-directional neighbors (up, right, down, left)
        int delr[] = {-1, 0, 1, 0}; // row changes
        int delc[] = {0, 1, 0, -1}; // column changes
        
        // Process pixels until there are none left in the queue
        while (!q.empty()) {
            // Get the current pixel coordinates
            auto idx = q.front();
            q.pop();
            
            // Check all 4 neighbors of the current pixel
            for (int i = 0; i < 4; i++) {
                int r = idx.first + delr[i];  // new row coordinate
                int co = idx.second + delc[i]; // new column coordinate
                
                // Check if neighbor is inside image boundaries,
                // has the original color, and is not already recolored
                if (r >= 0 && r < n && co >= 0 && co < m && c[r][co] != newColor && c[r][co] == intial) {
                    // Recolor the neighbor pixel
                    c[r][co] = newColor;
                    // Add the neighbor pixel to the queue to process its neighbors later
                    q.push({r, co});
                }
            }
        }
        
        // Return the modified image after flood fill
        return c;
    }
};

