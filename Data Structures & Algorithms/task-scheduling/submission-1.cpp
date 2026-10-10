class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freqs(26,0);
        int maxfreq=-1;
        for (char c : tasks){
            freqs[c-'A']++;
            maxfreq = max(maxfreq, freqs[c-'A']);
        }

        int count=0;
        for (int i=0; i<26; i++){
            if (freqs[i] == maxfreq) count++;   
        }

        int sum = tasks.size();
        if (sum==0) return 0;

        int temp = (maxfreq - 1)*(n+1) + (count);

        return max(sum, temp);

    }
};
