class Solution {
public:
    
    bool bfs(vector<vector<int>> &graph, int src, vector<bool> &visited){
         
        queue<int> q;
        q.push(src);
        
        map<int, int> m;
        m[src] = 0;
        
        while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it : graph[node]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                        m[it] = !m[node];
                    }else{
                        if(m[it] == m[node]) return false;
                    }
                }
            }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int v = graph.size();
        
        vector<bool> visited(v, false);

        for(int i = 0; i < v; i++){
             if(!visited[i]){
                 visited[i] = true;
                  if(!bfs(graph, i, visited)) return false;
            }   
        }
        
        return true;
    }
};