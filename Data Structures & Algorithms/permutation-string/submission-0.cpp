class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n = s1.length(), m = s2.length();
        if (n>m) return false;

        unordered_map<char, int> m1, m2;

        for (int i=0; i<n; i++){
            m1[s1[i]]++;
        }

        int l = 0, r = n-1;

        for (int i = l; i<=r; i++){
            m2[s2[i]]++;
        }

        while (r<m){
            
            if (m1 == m2) return true;

            if (r == m-1) break;

            m2[s2[l]]--;
            if (m2[s2[l]] == 0) m2.erase(s2[l]);
            l++;
            r++;
            m2[s2[r]]++;

        }

        return false;


    }
};
