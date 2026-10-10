class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n = words.size();
        if (n==1) return true;

        vector<int> letters(26);
        for (int i=0; i<order.size(); i++){
            letters[order[i] - 'a'] = i;
        }

        for (int i=0; i<n-1; i++){

            string prev = words[i], next = words[i+1];
            int j=0;
            int temp = 0;

            while (j<prev.length() && j<next.length()){

                if (letters[prev[j] - 'a'] < letters[next[j] - 'a']) {temp = 1; break;}
                else if (letters[prev[j] - 'a'] > letters[next[j] - 'a']) {temp = 2; break;}
                j++;

            }

            if (temp==1) continue;
            if (temp==2) return false;
            if (temp==0 && prev.length()>next.length()) return false;
            


        }


        return true;

    }
};