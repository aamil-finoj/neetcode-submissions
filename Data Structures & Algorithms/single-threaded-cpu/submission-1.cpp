class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        
        int n = tasks.size();
        for (int i=0; i<n; i++) tasks[i].push_back(i);
    
        sort(tasks.begin(), tasks.end());
        vector<int> ans;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //{duration, index}

        int time = tasks[0][0];
        int i=0;

    while (i < n || !pq.empty()) {
        if (pq.empty()) {
            time = max(time, tasks[i][0]);
        }

        while (i < n && tasks[i][0] <= time) {
            pq.push({tasks[i][1], tasks[i][2]});
            i++;
        }

        auto [dur, idx] = pq.top();
        pq.pop();
        ans.push_back(idx);
        time += dur;
    }



        return ans;
        



    }
};