class Solution {
public:


    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m));

        queue<pair<int, int>> q;
        int ans = 0;


        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (grid[i][j] == 1){
                    q.push({i,j});
                    vis[i][j] = true;
                    break;
                } 
                    
            } 
        }

        vector<pair<int, int>> directions = {{1,0}, {0,1}, {-1, 0}, {0, -1}};

        while (!q.empty()){

            int i = q.front().first;
            int j = q.front(). second;
            q.pop();

            for (const auto& [dx, dy] : directions){

                int temp_x = i+dx;
                int temp_y = j+dy;

                if (temp_x < 0 || temp_y < 0 || temp_x > n-1 || temp_y > m-1) ans++;
                else if (grid[temp_x][temp_y] == 0) ans++;

                else if (!vis[temp_x][temp_y]) {
                    vis[temp_x][temp_y] = true;
                    q.push({temp_x, temp_y});
                }

            }


        }

        return ans;


    }
};