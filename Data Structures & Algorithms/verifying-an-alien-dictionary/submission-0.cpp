class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n = words.size();
        if (n==1) return true;

        unordered_map<char, int> m;
        for (int i=0; i<order.size(); i++){
            m[order[i]] = i;
        }

        for (int i=0; i<n-1; i++){

            string prev = words[i], next = words[i+1];
            int j=0;
            int temp = 0;

            while (j<prev.length() && j<next.length()){
                
                if (m[prev[j]] < m[next[j]]) {temp = 1; break;}
                else if (m[prev[j]] > m[next[j]]) {temp = 2; break;}
                j++;

            }

            if (temp==1) continue;
            if (temp==2) return false;
            if (temp==0 && prev.length()>next.length()) return false;
            


        }


        return true;

    }
};