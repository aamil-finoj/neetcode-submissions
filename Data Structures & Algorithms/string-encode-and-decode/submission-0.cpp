class Solution {
public:

    string encode(vector<string>& strs) {

        if (strs.size() == 0) return "$EMPTY$";

        vector<int> sizes;
        string ans = "";
        for (string s : strs){
            sizes.push_back(s.length());
        }

        for (const auto it : sizes){
            ans+=to_string(it);
            ans+=',';
        }
        ans+='#';

        for (string s : strs){
            ans += s;
        }

        return ans;

    }

    vector<string> decode(string s) {

        if (s == "$EMPTY$") return {};


        vector<string> ans;
        vector<int> sizes;

        string temp = "";
        int n = s.length(), i;

        for (i = 0; i<n; i++){
            char c = s[i];

            if (c=='#') break;

            if (isdigit(c)) temp+=c;
            if (c == ','){
                sizes.push_back(stoi(temp));
                temp = "";
            }
        }

        i++;

        for (int j=0; j<sizes.size(); j++){

            int curr_size = sizes[j];
            string curr = s.substr(i, curr_size);
            ans.push_back(curr);
            i = i+curr_size;

        }
        


        return ans;



    }
};
