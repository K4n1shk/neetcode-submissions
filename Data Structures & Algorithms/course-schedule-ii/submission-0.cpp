class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto& preq: prerequisites){
            adj[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }

        queue<int> q;

        for(int i = 0; i< numCourses; i++){
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int completed = 0;
        vector<int> output;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            output.push_back(node);
            for(auto &x : adj[node]){
                indegree[x]--;
                if(indegree[x] == 0){
                    q.push(x);
                }
            }
            completed++;
        }
        return completed == numCourses ? output : vector<int>{};
    }
};
