class Solution {
public:

    double solve(int x, int y){
        return sqrt(pow(x,2) + pow(y,2));
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        priority_queue<pair<double, int>> pq;

        for (int i=0; i<points.size(); i++){

            int x = points[i][0], y=points[i][1];
            double dist = solve(x,y);
            pq.push({dist, i});

            if (pq.size()>k) pq.pop();

        }

        vector<vector<int>> ans;
        while (!pq.empty()){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;


    }
};
