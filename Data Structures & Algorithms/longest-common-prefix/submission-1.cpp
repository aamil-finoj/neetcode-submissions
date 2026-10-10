class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];
for (int i = 1; i < strs.size(); i++) {
    string temp = "";
    for (int j = 0; j < min(ans.length(), strs[i].length()); j++) {
        if (ans[j] == strs[i][j]) temp += ans[j];
        else break;
    }
    ans = temp;
    if (ans.empty()) return "";
}
return ans;


    }
};