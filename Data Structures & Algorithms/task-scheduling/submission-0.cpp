class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freqs(26,0);
        for (char c : tasks){
            freqs[c-'A']++;
        }

        priority_queue<int> pq; 
        int sum = 0;
        for (int i=0; i<26; i++){
            sum+=freqs[i];
            if (freqs[i]>0) pq.push(freqs[i]);
        }

        if (sum==0) return 0;

        int top_freq = pq.top();
        int count=0;
        while (!pq.empty()){
            if (pq.top()==top_freq){count++; pq.pop();}
            else break;
        }

        int temp = (top_freq - 1)*(n+1) + (count);

        return max(sum, temp);


    }
};
