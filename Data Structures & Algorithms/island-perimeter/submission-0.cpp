class Solution {
public:

    int dfs (vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis){

        
        if (i<0 || i>=grid.size()) return 1;
        if (j<0 || j>=grid[0].size()) return 1;
        if (vis[i][j]) return 0;
        if (grid[i][j] == 0) return 1;
    
        vis[i][j] = true;
        return dfs(grid, i+1, j, vis) +dfs(grid, i-1, j, vis) + dfs(grid, i, j+1, vis) + dfs(grid, i, j-1, vis);

    }



    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m));
        //int ans = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){

                if (grid[i][j] == 1)
                    return dfs(grid, i, j, vis);
                

            }
        }
        return 0;

    }
};