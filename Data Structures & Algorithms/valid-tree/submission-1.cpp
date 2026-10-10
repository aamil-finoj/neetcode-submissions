class Solution {
public:

    bool checkCycle(int node, int parent, vector<int> adj[], vector<bool>& vis){

        vis[node] = true;

        for (auto it : adj[node]){
            if (it==parent) continue;
            if (vis[it]) return true;
            if (checkCycle(it, node, adj, vis) == true) return true;
        }

        return false;

    }


    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size()!=n-1) return false;

        vector<int> adj[n];
        vector<bool> vis(n);

        for (const auto& it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        if (checkCycle(0, -1, adj, vis) == true) return false;

        for (int i=0; i<n; i++){
            if (!vis[i]) return false;
        }

        return true;

    }
};
