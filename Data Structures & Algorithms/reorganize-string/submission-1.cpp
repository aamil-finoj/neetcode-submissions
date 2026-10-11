class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        string ans = "";
        vector<int> freqs(26);
        char prev = 'X'; int prevFreq = 0;

        for (int i=0; i<n; i++) {
            freqs[s[i]-'a']++;
            if (freqs[s[i] - 'a'] > (n + 1) / 2) return "";
        }

        priority_queue<pair<int, char>> pq;

        for (int i=0; i<26; i++) if (freqs[i]>0) pq.push({freqs[i], 'a'+i});

        while (!pq.empty() || prevFreq>0){

            if (prevFreq>0 && pq.empty()) return "";

            int f = pq.top().first;
            char c = pq.top().second;
            pq.pop();

            ans+=c;
            f--;

            if (prevFreq>0) pq.push({prevFreq, prev});
            prevFreq = f;
            prev = c;

        }

        return ans;

    }
};