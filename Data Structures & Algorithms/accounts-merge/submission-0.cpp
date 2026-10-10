class Solution {
    unordered_map<string, int> emailIdx; 
    vector<string> emails; 
    unordered_map<int, int> emailToAcc; 
    vector<vector<int>> adj;
    unordered_map<int, vector<string>> emailGroup; 
    vector<bool> vis;

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        int m = 0;

        // Build email index and mappings
        for (int accId = 0; accId < n; accId++) {
            vector<string>& account = accounts[accId];
            for (int i = 1; i < account.size(); i++) {
                string& email = account[i];
                if (emailIdx.find(email) == emailIdx.end()) {
                    emails.push_back(email);
                    emailIdx[email] = m;
                    emailToAcc[m] = accId;
                    m++;
                }
            }
        }

        // Build adjacency list
        adj.resize(m);
        for (auto& account : accounts) {
            for (int i = 2; i < account.size(); i++) {
                int id1 = emailIdx[account[i]];
                int id2 = emailIdx[account[i - 1]];
                adj[id1].push_back(id2);
                adj[id2].push_back(id1);
            }
        }

        vis.resize(m, false);
        // DFS traversal
        for (int i = 0; i < m; i++) {
            if (!vis[i]) {
                int accId = emailToAcc[i];
                dfs(i, accId);
            }
        }

        // Build result
        vector<vector<string>> res;
        for (auto& [accId, group] : emailGroup) {
            sort(group.begin(), group.end());
            vector<string> merged;
            merged.push_back(accounts[accId][0]);
            merged.insert(merged.end(), group.begin(), group.end());
            res.push_back(merged);
        }

        return res;
    }

private:
    void dfs(int node, int& accId) {
        vis[node] = true;
        emailGroup[accId].push_back(emails[node]);
        for (int& neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, accId);
            }
        }
    }
};