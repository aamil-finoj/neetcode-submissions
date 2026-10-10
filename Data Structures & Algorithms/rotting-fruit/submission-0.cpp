class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int fresh=0;

        queue<pair<int,int>> q;

        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){

                if (grid[i][j] == 2) q.push({i,j});
                if (grid[i][j] == 1) fresh++;

            }
        }

        if (fresh==0) return 0;

        int minute=0;
        while (!q.empty()){
            
            int temp = q.size();
            bool changed = false;

            while (temp--){

                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (auto [dx,dy] : directions){
                    int nx = x+dx, ny = y+dy;

                    if (nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if (grid[nx][ny] == 0 || grid[nx][ny] == 2) continue;

                    grid[nx][ny] = 2;
                    fresh--;
                    changed = true;

                    q.push({nx,ny});
                }
            }

            if (changed) minute++;


        }

        return (fresh==0 ? minute : -1);

    }
};
