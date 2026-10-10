class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        int n = numCourses;
        vector<int> indegrees(n);
        vector<int> adj[n];

        unordered_map<int, unordered_set<int>> prereqs;

        for (const auto& it : prerequisites){

            adj[it[0]].push_back(it[1]);
            indegrees[it[1]]++;

        }

        queue<int> q;

        for (int i=0; i<n; i++) {
            if (indegrees[i]==0) 
            q.push(i);
            prereqs[i] = {};
        }

        while (!q.empty()){
            
            int curr = q.front();
            q.pop();

            for (auto it : adj[curr]){
                indegrees[it]--;
                if (indegrees[it] == 0){
                    q.push(it);
                }
                
                prereqs[it].insert(curr);
                prereqs[it].insert(prereqs[curr].begin(), prereqs[curr].end());
                
            }

        }

        vector<bool> ans;
        for (const auto& query : queries){

            if (prereqs[query[1]].count(query[0])) ans.push_back(true);
            else ans.push_back(false);

        }

        return ans;



    }
};