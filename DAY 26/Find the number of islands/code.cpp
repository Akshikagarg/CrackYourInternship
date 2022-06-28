class Solution {
  public:
    // Function to find the number of islands.
     void DFS(vector<vector<char>> &grid, int i, int j, int rows, int cols)
    {
        // edge condtion
        if (i < 0 || i > rows-1 || j < 0 || j > cols-1 || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        DFS(grid, i + 1, j, rows, cols);
        DFS(grid, i - 1, j, rows, cols);
        DFS(grid, i, j + 1, rows, cols);
        DFS(grid, i, j - 1, rows, cols);
        DFS(grid, i - 1, j - 1, rows, cols);
        DFS(grid, i - 1, j + 1, rows, cols);
        DFS(grid, i + 1, j - 1, rows, cols);
        DFS(grid, i + 1, j + 1, rows, cols);
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
    
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                // if this is the island
                if (grid[i][j] == '1')
                {
                    count++;
                    // call the dfs for all the 8 directions
                    DFS(grid, i, j, rows, cols);
                }
            }
        }
        return count;
    }
};

