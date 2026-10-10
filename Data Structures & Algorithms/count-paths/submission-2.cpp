class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> row(n,1);

        for (int i=0; i<m-1; i++){
            vector<int> temp(n,1);
            for (int j=n-2; j>=0; j--){
                temp[j] = temp[j+1] + row[j];
            }
            row = temp;
        }

        return row[0];


    }
};
