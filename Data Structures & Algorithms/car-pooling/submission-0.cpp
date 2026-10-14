class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        
        int n = trips.size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        //end time, capacity

        sort(trips.begin(), trips.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1]<b[1];
        } );

        pq.push({trips[0][2], trips[0][0]});

        int carrying=trips[0][0];

        for (int i=1; i<n; i++){

            int ppl = trips[i][0];
            int from = trips[i][1];
            int to = trips[i][2];

            while (!pq.empty() && pq.top().first <= from){
                carrying -= pq.top().second;
                pq.pop();
            }

            if (carrying+ppl > capacity) return false;
            carrying+=ppl;
            pq.push({to, ppl});


        }


        return true;




    }
};