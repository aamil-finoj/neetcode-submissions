class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        int n = profits.size();

        vector<pair<int,int>> arr(n);
        for (int i=0; i<n; i++){
            arr[i] = {capital[i], profits[i]};
        }

        sort(arr.begin(), arr.end(), [](const pair<int,int>& a, const pair<int,int>& b){
            if (a.first==b.first) return a.second>b.second;
            else return a.first<b.first;
        });

        if (w<arr[0].first) return w;  

        priority_queue<int> pq; //profit
        
        int i=0;
        while (k){

            while (i<n && arr[i].first<=w){
                pq.push(arr[i].second);
                i++;
            }

            if (pq.empty()) break;
            w+=pq.top();
            pq.pop();
            k--;

            // if (k==0) break;



        }

        return w;


    }
};