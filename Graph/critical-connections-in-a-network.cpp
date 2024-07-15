class Solution {
public:
int tin[100007],low[100007];
vector<vector<int>>bridges;
int tim=1;
void dfs(int node,int parent,vector<vector<int>>&adj,vector<int>&vis){
   tin[node]=low[node]=tim++;
   vis[node]=true;
   for(int c : adj[node]){
    if(c==parent) continue;
    if(vis[c]) low[node]=min(low[node],low[c]);
    else{
        dfs(c,node,adj,vis);
        low[node]=min(low[node],low[c]);
        if(low[c] > tin[node]){
            bridges.push_back({c,node});
        }
    }
   }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto c : connections){
            int u=c[0];
            int v=c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(n,false);
        dfs(0,-1,adj,vis);
        return bridges;
    }
};