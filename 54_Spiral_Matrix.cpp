// LeetCode 54 - Spiral Matrix

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;

        vector<int> ans;

        while (left <= right && top <= bottom) {

            // Traverse Left -> Right
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);
            top++;

            // Traverse Top -> Bottom
            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);
            right--;

            // Traverse Right -> Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--)
                    ans.push_back(matrix[bottom][i]);
                bottom--;
            }

            // Traverse Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    ans.push_back(matrix[i][left]);
                left++;
            }
        }

        return ans;
    }
};

/*
-------------------------------------------------------
Approach:
-------------------------------------------------------

Maintain four boundaries:
1. top    -> First unvisited row
2. bottom -> Last unvisited row
3. left   -> First unvisited column
4. right  -> Last unvisited column

Traverse the matrix in four directions:

1. Left -> Right  (Top row)
   - Print all elements from left to right.
   - Increment top.

2. Top -> Bottom (Right column)
   - Print all elements from top to bottom.
   - Decrement right.

3. Right -> Left (Bottom row)
   - Print all elements from right to left.
   - Decrement bottom.
   - Execute only if top <= bottom.

4. Bottom -> Top (Left column)
   - Print all elements from bottom to top.
   - Increment left.
   - Execute only if left <= right.

Repeat until all elements are visited.

-------------------------------------------------------
Why are the if conditions required?
-------------------------------------------------------

if(top <= bottom)
    Prevents printing the bottom row twice when only one row remains.

if(left <= right)
    Prevents printing the left column twice when only one column remains.

-------------------------------------------------------
Time Complexity : O(m * n)
Space Complexity: O(1)  (excluding output vector)

*/