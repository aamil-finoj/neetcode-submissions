class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int maxArea = 0;

        static const int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){

                if (grid[i][j] == 0) continue;

                int currArea = 0;
                queue<pair<int, int>> q;
                grid[i][j] = 0;
                currArea++;
                q.push({i, j});

                while (!q.empty()){

                    const auto [x,y] = q.front();
                    q.pop();
                    
                    for (const auto& [dx,dy] : directions){
                        int x_temp = x+dx, y_temp = y+dy;

                        if (x_temp<0 || y_temp<0 || x_temp>=n || y_temp>=m) continue;
                        if (grid[x_temp][y_temp] == 0) continue;

                        q.push({x_temp, y_temp});
                        grid[x_temp][y_temp] = 0;
                        currArea++;
                        
                        
                    }


                }

                maxArea = max(maxArea, currArea);


            }
        }

        return maxArea;


    }
};
