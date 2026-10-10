class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.length();

        for (int i=0; i<n; i++){
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
                st.push(c);

            if (c==')'){
                if (st.empty() || st.top()!='(') return false;
                else st.pop();
            }

            if (c=='}'){
                if (st.empty() || st.top()!='{') return false;
                else st.pop();
            }

            if (c==']'){
                if (st.empty() || st.top()!='[') return false;
                else st.pop();
            }

        }

        if (st.empty()) return true;
        else return false;


    }
};
