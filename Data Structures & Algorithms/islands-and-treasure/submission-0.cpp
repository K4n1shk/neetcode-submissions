class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        vector<vector<int>> dirns {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
            };
        
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> q;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [a,b] = q.front();
            q.pop();
            for(const auto& dir : dirns){
                int r = a + dir[0];
                int c = b + dir[1];

                if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != INT_MAX){
                    continue;
                }

                grid[r][c] = 1 + grid[a][b];
                q.push({r,c});
            }
        }
    }
};
