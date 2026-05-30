class Solution {
    private static int[][] direction = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    void dfs(char[][] grid, int row, int col){
        if(row < 0 || col < 0 || row >= grid.length || col >= grid[0].length || grid[row][col] == '0'){
            return;
        }

        grid[row][col] = '0';

        for(int i = 0;i<direction.length;i++){
            dfs(grid, row + direction[i][0], col + direction[i][1]);
        }
    }

    public int numIslands(char[][] grid) {
        int row = grid.length;
        int col = grid[0].length;
        int island = 0;

        for(int i = 0;i<row;i++){
            for(int j =0;j<col;j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    island++;
                }
            }
        }
        return island;
    }


}
