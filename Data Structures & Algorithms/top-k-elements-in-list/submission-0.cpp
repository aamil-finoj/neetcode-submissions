class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        int n = nums.size();
        vector<vector<int>> freqLists(n+1);

        vector<int> ans;

        for (int i=0; i<n; i++){
            freqMap[nums[i]]++;
        }

        for (const auto& [value, freq] : freqMap){
            freqLists[freq].push_back(value);
        }

        int i = n;
        while (k>0){
            if (freqLists[i].size() == 0) {i--; continue;}
            else{
                int m = freqLists[i].size();
                for (int j = 0; j<m; j++){
                    ans.push_back(freqLists[i][j]);
                    k--;
                    if (k==0) break;
                }
                i--;
            }
        }

        return ans;


    }
};
