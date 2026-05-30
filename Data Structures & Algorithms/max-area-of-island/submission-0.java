class Solution {
    private static int[][] direction = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    int dfs(int[][] grid, int row, int col) {
        if (row < 0 || col < 0 ||
            row >= grid.length ||
            col >= grid[0].length ||
            grid[row][col] == 0) {
            return 0;
        }

        grid[row][col] = 0; // mark visited

        int area = 1; // current land cell

        for (int i = 0; i < direction.length; i++) {
            area += dfs(
                grid,
                row + direction[i][0],
                col + direction[i][1]
            );
        }

        return area;
    }

    public int maxAreaOfIsland(int[][] grid) {
        int rows = grid.length;
        int cols = grid[0].length;
        int maxArea = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = Math.max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
}