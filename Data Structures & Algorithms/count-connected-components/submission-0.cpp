class Solution {
public:

    void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis){

        //if (vis[i]) return;
        vis[i] = true;

        for (auto it : adj[i]){
            if (!vis[it]) dfs(it, adj, vis);
        }

        return;

    }

    int countComponents(int n, vector<vector<int>>& edges) {

        vector<bool> vis(n);
        vector<vector<int>> adj(n);

        for (const auto& it : edges){

            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);

        }

        int ans = 0;

        for (int i=0; i<n; i++){
            if (!vis[i]){
                ans++;
                dfs(i, adj, vis);
            }
        }

        return ans;


    }
};
