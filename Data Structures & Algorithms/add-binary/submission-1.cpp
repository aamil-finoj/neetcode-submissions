class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.length()-1, j = b.length()-1;
        int carry = 0;

        while (i>=0 || j>=0 || carry>0){

            int A = (i>=0 ? a[i] - '0' : 0);
            int B = (j>=0 ? b[j] - '0': 0);

            int total = A+B+carry;
            ans+=to_string(total%2);

            if (total>=2) carry = 1;
            else carry = 0;

            i--; j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};