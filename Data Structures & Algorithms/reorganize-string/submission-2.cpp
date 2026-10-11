class Solution {
public:
    string reorganizeString(string s) {
        
        int n = s.length();
        string ans = "";
        vector<int> freqs(26);

        for (int i=0; i<n; i++) {
            freqs[s[i]-'a']++;
            if (freqs[s[i] - 'a'] > (n + 1) / 2) return "";
        }

        priority_queue<pair<int, char>> pq;

        for (int i=0; i<26; i++) if (freqs[i]>0) pq.push({freqs[i], 'a'+i});

        while (pq.size()>=2){

            auto [f1,c1] = pq.top(); pq.pop();
            auto [f2,c2] = pq.top(); pq.pop();

            ans+=c1; ans+=c2;
            f1--;
            f2--;

            if (f1>0) pq.push({f1,c1});
            if (f2>0) pq.push({f2,c2});

        }
        while (!pq.empty()){
            ans+=pq.top().second;
            pq.pop();
        }

        return ans;

    }
};