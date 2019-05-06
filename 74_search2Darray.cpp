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
		
		return binarySearch(matrix, n, 0, m*n-1, target);
	}

    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
		if (m == 0) return false;

        int n = matrix[0].size();
		if (n == 0) return false;

        int row = searchRow(matrix, 0, m-1, n, target);
        if (row == -1) return false;
        return searchValue(matrix[row], 0, n-1, target);
    }
    
private:
	bool binarySearch(vector<vector<int>>& matrix, int n, int i, int j, int target) {
		if (i > j) return false;

		int mid = (i + j)/2;
		int row = mid / n;
		int col = mid % n;

		if (matrix[row][col] == target) return true;

		if (matrix[row][col] > target) {
			return binarySearch(matrix, n, i, mid-1, target);
		} else {
			return binarySearch(matrix, n, mid+1, j, target);
		}
	}

    int searchRow(vector<vector<int>>& matrix, int p, int q, int n, int target) {
        if (p > q) {
            return -1;
        }
        
        int mid = (p + q)/2;
		if (matrix[mid][0] <= target && matrix[mid][n-1] >= target ) {
			return mid;
		} else if (matrix[mid][0] > target) {
            return searchRow(matrix, p, mid-1, n, target);
        } else if (matrix[mid][n-1] < target) {
            return searchRow(matrix, mid+1, q, n, target);
        }
    }
    
    bool searchValue(vector<int>& arr, int i, int j, int target) {
        if (i > j) return false;
        int mid = (i+j)/2;
		if (arr[mid] == target) {
			return true;
		}
        
        if (arr[mid] > target) {
            return searchValue(arr, i, mid-1, target);
        } else {
            return searchValue(arr, mid+1, j, target);
        }
    }
};

int main() {
	vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
	Solution sol;
	cout << "Find 3? " << (sol.searchMatrix(matrix, 3)==true? "Found" : "Not Found") << endl;
	cout << "Find 0? " << (sol.searchMatrix(matrix, 0)==true? "Found" : "Not Found") << endl;

	vector<vector<int>> empty;
	cout << "Find 0? " << (sol.searchMatrix(empty, 0)==true? "Found" : "Not Found") << endl;

	return 0;
}
