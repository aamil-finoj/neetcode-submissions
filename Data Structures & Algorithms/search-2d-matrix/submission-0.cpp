class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        if (target<matrix[0][0] || target>matrix[m-1][n-1]) return false;

        int u = 0, d = m-1;
        int row = -1;

        while (u<=d){
            int mid = u + (d-u)/2;
            if (target >= matrix[mid][0] && target <= matrix[mid][n - 1]) {
                row = mid; 
                break;
            }
            else if (matrix[mid][0] > target) d = mid-1;
            else u = mid+1;
        }

        if (row == -1) return false;

        int l = 0, r = n-1;

        while (l<=r){
            int mid = l + (r-l)/2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] > target) r = mid-1;
            else l = mid+1;
        }

        return false;


    }
};
