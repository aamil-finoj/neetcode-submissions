class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if (n==1) return strs[0];

        string a = strs[0], b = strs[1];

        for (int i=0; i<min(a.length(), b.length()); i++){
            if (a[i]==b[i]) ans+=a[i];
            else break;
        }

        int m = ans.length();

        for (int i=2; i<n; i++){

            string current = strs[i];
            string temp = "";
            for (int j = 0; j<min((int)current.length(), m); j++){
                if (current[j]==ans[j]) temp+=current[j];
                else break; 
            }

            ans = (ans.length()<=temp.length() ? ans : temp);

        }
        return ans;


    }
};