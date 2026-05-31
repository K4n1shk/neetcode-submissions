class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int fresh = 0;
        int minute = 0;
        for(int i = 0 ;i < grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1) fresh++;
                if(grid[i][j] == 2) q.push({i,j});
            }
        }

        vector<vector<int>> dirns {
            {0,1},
            {0,-1},
            {1,0},
            {-1,0}
            };

        while(!q.empty() and fresh > 0){
            int length = q.size();
            for(int i = 0;i< length;i++){
                auto index = q.front();
                q.pop();
                int row = index.first;
                int col = index.second;

                for(int i = 0 ;i < 4;i++){
                    int r = row + dirns[i][0];
                    int c = col + dirns[i][1];
                    
                    if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || 
                        grid[r][c] == 2 || grid[r][c] == 0
                    ) continue;
                    grid[r][c] = 2;
                    q.push({r,c});
                    fresh--;
                }
            }
            minute++;
        }
        return fresh == 0 ? minute : -1;
    }
};
