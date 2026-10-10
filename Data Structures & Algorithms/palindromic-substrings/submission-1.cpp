class Solution {
public:
    int countSubstrings(string s) {
        
        int n = s.length();
        int count=n;

        vector<int> checker;

        for (int i=0; i<n; i++){

            int l = i-1, r=i+1;
            while (l>=0 && r<n){
                if (s[l] == s[r]) count++;
                else break;
                l--;
                r++;
            }

            l = i; r=i+1;
            while (l>=0 && r<n){
                if (s[l] == s[r]) count++;
                else break;
                l--;
                r++;
            }

            checker.push_back(count);

        }

        for (int i=0; i<n; i++) cout<<checker[i]<<" ";
        cout<<endl;

        return count;



    }
};
