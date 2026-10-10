class Solution {

private:
    unordered_map<int, int> m;

public:

    int solve(int i, string& s){

        if (m.count(i)) return m[i];
        if (s[i] == '0') return 0;
        //if (i==s.length()-1) return 1;

        if (i<s.length()-1 && s[i] == '1' ) m[i] = solve(i+1,s) + solve(i+2,s);
        else if (i<s.length()-1 && s[i] == '2' && s[i+1]<='6') m[i] = solve(i+1,s) + solve(i+2,s);
        else m[i] = solve(i+1,s);

        return m[i];

    }

    int numDecodings(string s) {
        m[s.length()] = 1;
        return solve(0,s);
    }
};
