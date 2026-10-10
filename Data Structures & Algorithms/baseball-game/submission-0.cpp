class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n = operations.size();

        for (int i=0; i<n; i++){
            string& curr = operations[i];

            if (curr=="+"){
                int x = st.top(); st.pop();
                int y = st.top(); st.pop();
                int sum = x+y;

                st.push(y);
                st.push(x);
                st.push(sum);
            
            }

            else if (curr=="C"){
                st.pop();
            }

            else if (curr=="D"){
                int x = st.top();
                st.push(2*x);
            }

            else st.push(stoi(curr));

        
        }

        int ans = 0;
        while (!st.empty()){
            ans+=st.top();
            st.pop();
        }

        return ans;



    }
};