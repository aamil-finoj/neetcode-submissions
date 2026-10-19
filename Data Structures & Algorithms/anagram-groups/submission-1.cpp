class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> m;

        for (string& s : strs){

            vector<int> freqs(26,0);
            for (char c : s) freqs[c-'a']++;

            string temp;
            for (int i=0; i<26; i++){
                temp+=to_string(freqs[i]) + ',';
            }
            m[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for (const auto& it : m) ans.push_back(it.second);

        return ans;
    }
};
