#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0) return false;
        int n = matrix[0].size();
        if (n == 0) return false;
        
        return searchHelper(matrix, 0, m-1, 0, n-1, target);
    }
    
private:
    bool searchHelper(vector<vector<int>>& matrix, int start_row, int end_row, int start_col, int end_col, int target) {
        if (start_row > end_row || start_col > end_col) return false;

		if (end_row - start_row <= 1 && end_col - start_col <= 1) {
			// Base case is when the matrix has size smaller than or equal to 2x2
			for (int i = start_row; i <= end_row; i++) {
				for (int j = start_col; j <= end_col; j++) {
					if (matrix[i][j] == target) return true;
				}
			}
			return false;
		}
        
        int mid_row = (start_row + end_row)/2;
        int mid_col = (start_col + end_col)/2;

        if (matrix[mid_row][mid_col] == target) return true;

        bool found = false;
        if (matrix[mid_row][mid_col] > target) {
            found = searchHelper(matrix, start_row, mid_row, start_col, mid_col, target);
            if (found) return true;
        } else {
            found = searchHelper(matrix, mid_row, end_row, mid_col, end_col, target);
            if (found) return true;
        }
        
        return searchHelper(matrix, mid_row+1, end_row, start_col, mid_col-1, target) || searchHelper(matrix, start_row, mid_row-1, mid_col+1, end_col, target);
    }
};


int main() {
	vector<vector<int>> matrix{{1,4,7,11,15}, {2,5,8,12,19}, {3,6,9,16,22}, {10,13,14,17,24}, {18,21,23,26,30}};
	Solution sol;
	cout << "Found 20? " << (sol.searchMatrix(matrix, 20)? "Found" : "Not Found") << endl;
	return 0;
}
