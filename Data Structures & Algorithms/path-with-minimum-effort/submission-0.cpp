class Solution {

private: 
    vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> dist (n, vector<int>(m,INT_MAX));
        dist[0][0] = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        pq.push({0,0,0});

        while (!pq.empty()){

            auto temp = pq.top();
            pq.pop();

            int delta = temp[0], x=temp[1], y=temp[2];

            if (x==n-1 && y==m-1) return delta;

            if (dist[x][y] < delta) continue;

            for (auto& [dx,dy] : directions){

                int nx = x+dx, ny = y+dy;
                if (nx<0 || ny<0 || nx>=n || ny>=m) continue;

                int temp = max(delta,abs(heights[nx][ny] - heights[x][y]));

                if (temp < dist[nx][ny]){
                    dist[nx][ny] = temp;
                    pq.push({temp, nx, ny});
                    
                }

            }


        }


        return 0;




    }
};