class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n = temperatures.size();
        stack<pair<int,int>> st;
        vector<int> ans(n);

        for (int i = n-1; i>=0; i--){
            int current = temperatures[i];

            if (st.empty()){
                ans[i] = 0;
                st.push({current, i});
            }
            else{
                while(!st.empty() && st.top().first<=current){
                    st.pop();
                }
                ans[i] = {st.empty() ? 0 : st.top().second - i};
                st.push({current, i});
            }
        }

        return ans;
    }
};
