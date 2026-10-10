class Solution {
public:

    int perform(int x, int y, const string& it){
        if (it == "+") return x+y;
        else if (it == "-") return x-y;
        else if (it == "*") return x*y;
        else if (it == "/") return x/y;

        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (const auto& it : tokens){

            if (it=="+" || it=="-" || it=="*" || it=="/"){
                
                int y = st.top();
                st.pop();

                int x = st.top();
                st.pop();

                int result = perform(x,y,it);
                st.push(result);
            }
            else{
                st.push(stoi(it));
            }
 
        }

        if (!st.empty()) return st.top();

        return 0;


    }
};
