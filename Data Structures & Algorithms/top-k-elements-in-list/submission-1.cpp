class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> m;
        vector<vector<int>> freqs(n+1);

        for (int i=0; i<n; i++){
            m[nums[i]]++;
        }

        for (auto& [val, freq] : m){
            freqs[freq].push_back(val);
        }

        int i = n;
        vector<int> ans;

        while (k>0 && i>=0){
            
            if (!freqs[i].empty()){
                int m = freqs[i].size();
                for (int j = 0; j<m; j++){
                    ans.push_back(freqs[i][j]);
                    k--;
                    if (k==0) break;
                }
            }

            i--;


        }
        return ans;

    }
};
