class Solution {
public:
    string longestPalindrome(string s) {

        int n = s.length();
        
        int idx = -1;
        int maxLength = 0;
        bool isOdd = false;

        for (int i=0; i<s.length(); i++){

            int oddLength = 1;
            int evenLength = 0;
            
            int l = i-1, r=i+1;

            while (l>=0 && r<n){

                if (s[l] == s[r]){
                    oddLength+=2;
                    l--;
                    r++;
                }
                else break;
            }
            if (oddLength > maxLength){maxLength = oddLength; idx=l+1;}

            l=i; r=i+1;
            while (l>=0 && r<n){

                if (s[l] == s[r]){
                    evenLength+=2;
                    l--;
                    r++;
                }
                else break;
            }
            if (evenLength > maxLength){maxLength = evenLength; idx=l+1;}

        }


        return s.substr(idx, maxLength);





    }
};
