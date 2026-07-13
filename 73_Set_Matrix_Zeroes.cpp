/*
Problem: Set Matrix Zeroes (LeetCode 73)

Approach:
1. Traverse the entire matrix.
2. Whenever a 0 is found, mark its row and column in two separate arrays:
      - row[i] = 1
      - col[j] = 1
3. Traverse the matrix again.
4. If row[i] == 1 or col[j] == 1, set matrix[i][j] = 0.

Why do we need row[] and col[]?
--------------------------------
If we immediately change a row or column to 0 while traversing,
those newly inserted zeros will also be treated as original zeros,
leading to incorrect results.

Example:
1 1 1
1 0 1
1 1 1

If we immediately make the row and column zero,
new zeros will keep spreading and eventually the entire matrix
becomes zero, which is wrong.

So first we "mark" the affected rows and columns,
then update the matrix in a second traversal.

Complexity:
-----------
Time  : O(n * m)
Space : O(n + m)

Key Concepts:
-------------
- matrix.size()      -> Number of rows
- matrix[0].size()  -> Number of columns
- vector<int> row(n,0) creates a marker array of size n initialized with 0.
- vector<int> col(m,0) creates a marker array of size m initialized with 0.

Follow-up:
----------
An optimized solution exists with O(1) extra space by using
the first row and first column as marker arrays.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Mark rows and columns containing zero
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Update the matrix
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] || col[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};