class Solution {
public:
    
    int parent[100001];
    int rank[100001];
    

    int find(int node){
        if(parent[node] == node) return node;
        
        return parent[node] = find(parent[node]);
    }
    
    void unions(int u, int v){
        u = find(u); v = find(v);
        
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[v] > rank[u]) parent[u] = v;
        else{
            parent[v] = u;
            rank[u]++;
        }
    }
    
    
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            parent[i] = i;
            rank[i] = 0;
        }
        
        vector<int> ch(n);
        for(int i = 0; i < n; i++){
            ch[i] = s[i] - 0;
        }
        
        int nEdges = pairs.size();
        for(auto p : pairs){
            unions(p[0], p[1]);
        }
        
        // this map will store elements in increasing order for each set;
        map<int, priority_queue<int, vector<int>, greater<int>>> m;
        
        for(int i = 0; i < n; i++){
            int nodeParent = find(i);
            m[nodeParent].push(ch[i]);
        }
        string ans = "";
        for(int i = 0; i < n; i++){
            int p = find(i);
            ans += (char) m[p].top();
            m[p].pop();
        }
       
        
        return ans;
    }
};