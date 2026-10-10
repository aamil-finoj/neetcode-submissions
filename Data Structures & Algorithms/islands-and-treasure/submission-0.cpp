class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        queue<pair<int,int>> q;

        for (int i = 0; i<n; i++){
            for  (int j=0; j<m; j++){

                if (grid[i][j] == 0) q.push({i,j});


            }
        }

        int level=1;
        while (!q.empty()){
            int temp = q.size();

            while (temp--){

                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto [dx,dy] : directions){
                    int nx = x+dx, ny = y+dy;
                    if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if (grid[nx][ny] < level) continue;
                    grid[nx][ny] = level;

                    q.push({nx,ny});
                }
            }

            level++;


        }

        return;
    }
};
