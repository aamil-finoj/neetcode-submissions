class Solution {
public:
    bool isPalindrome(string s) {
        
        int i,j;
        int n = s.length();

        i=0; j=n-1;

        while (i<=j){
            if (!isalnum(s[i])) {i++; continue;}
            if (!isalnum(s[j])) {j--; continue;}
            if (tolower(s[i])!=tolower(s[j])) return false;
            i++;
            j--;
    
        }

        return true;

    }
};
