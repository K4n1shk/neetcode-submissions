class DSU{
    private:
        vector<int> parent;
        vector<int> rank;
        int component;
    
    public:
        DSU(int n){
            component = n+1;
            parent.resize(n+1);
            rank.resize(n+1,1); // size + initialization
            for(int i = 0;i<n+1;i++){
                parent[i] = i;
            }
        }

        int find(int x){
            if(parent[x] == x){
                return x;
            }
            parent[x] = find(parent[x]);
            return parent[x];
        }

        bool unite(int a, int b){
            int rootA = find(a);
            int rootB = find(b);

            if (rootA == rootB) return false;

            if(rank[rootA] < rank[rootB]){
                parent[rootA] = rootB;
            }else if (rank[rootA] > rank[rootB]){
                parent[rootB] = rootA;
            }else{
                parent[rootA] = rootB;
                rank[rootB]++;
            }
            component--;
            return true;
        }

        int components(){
            return component;
        }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DSU dsu(n);
        for(auto& edge: edges){
            if(!dsu.unite(edge[0],edge[1])){
                return vector<int>{edge[0],edge[1]};
            }
        }
        return vector<int>{};
    }
};
