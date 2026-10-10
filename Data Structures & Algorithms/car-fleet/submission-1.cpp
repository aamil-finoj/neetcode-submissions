class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> arr(n);

        for (int i=0; i<n; i++){
            arr[i] = {position[i], speed[i]};
        }

        sort(arr.begin(), arr.end());

        stack<double> st;

        for (int i = n-1; i>=0; i--){

            double curr_time = (double)(target-arr[i].first) / arr[i].second;
            if (st.empty()) st.push(curr_time);
            else if (curr_time>st.top())
                st.push(curr_time);

        }
        return st.size();

    }
};
