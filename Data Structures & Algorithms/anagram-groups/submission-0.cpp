class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> anagrams;
        for (auto current : strs){
            string temp = current;
            sort(temp.begin(), temp.end());

            if (!anagrams.count(temp)){
                anagrams[temp] = {current};

            }
            else anagrams[temp].push_back(current);

        }

        vector<vector<string>> ans;
        for (auto it : anagrams){
            ans.push_back(it.second);
        }

        return ans;

    }
};
