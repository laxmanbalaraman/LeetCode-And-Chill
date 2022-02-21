
// can also be done using dfs and for loops to visited all components of graphs

class Solution {
public:
    int parent[201];
    int rank[201];
    
    void unions(int u, int v){
        u = find(u);
        v = find(v);
        
        if(rank[u] > rank[v]){
            parent[v] = u;
        }else if(rank[v] > rank[u]){
            parent[u] = v;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    int find(int node){
        if(parent[node] == node) return node;
        return parent[node] = find(parent[node]); 
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        
        // init parent
        for(int i = 0; i < v; i++){
            parent[i] = i;
        }
        
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(isConnected[i][j]){
                    unions(i, j);
                }
            }
        }
        
        // path compress every node
        for(int i = 0; i < v; i++) find(i);
        
        set<int> s;
        for(int i = 0; i < v; i++) s.insert(parent[i]);
        
        return s.size();
    }
};