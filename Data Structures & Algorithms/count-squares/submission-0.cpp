class CountSquares {
private:
    vector<vector<int>> points;
    unordered_map<int,unordered_map<int,int>> countMap;

public:
    CountSquares() {
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        countMap[x][y]++;
        points.push_back(point);
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];

        int ans = 0;
        for(auto& p : points){
            int px = p[0];
            int py = p[1];

            if(x == px || y == py) continue;

            if(abs(x - px) != abs(y - py)) continue;

            ans += countMap[x][py] * countMap[px][y];
        }
        return ans;
    }
};
