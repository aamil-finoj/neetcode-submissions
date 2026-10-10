class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        int longest = 1;
        int curr_length=1;

        if (n==0) return 0;

        vector<bool> vis(n, 0);

        unordered_map<int, vector<int>> indices;

        for (int i=0; i<n; i++){
            indices[nums[i]].push_back(i);
        }

        for (int i = 0; i<n; i++){
            if (vis[i]) continue;

            vis[i] = true;
            curr_length = 1;
            int temp = nums[i];

            while(1){
                
                if (indices.count(temp+1)){
                    curr_length++;
                    for (auto it : indices[temp+1]){
                        vis[it] = true;
                    }
                    temp++;
                }
                else break;
            }

            longest = max(curr_length, longest);

        }

        return longest;


    }
};
