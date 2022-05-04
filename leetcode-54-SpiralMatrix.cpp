/** https://leetcode.com/problems/spiral-matrix/

Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:


Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

*/


/**
    Runtime: 0 ms
    Memory Usage: 6.9 MB
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int up = 0, down = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
        vector<int> ans;
        
        int direction = 0;
        while(up <= down && left <= right){
            if(direction == 0){ // right
                for(int j = left; j <= right; ++j)
                    ans.push_back(matrix[up][j]);
                up ++;
            }
            if(direction == 1){ //down
                for(int i = up; i <= down; ++i)
                    ans.push_back(matrix[i][right]);
                right --;
            }
            if(direction == 2){ //left
                for(int j = right; j >= left; j--)
                    ans.push_back(matrix[down][j]);
                down --;
            }
            if(direction == 3){ //up
                for(int i = down; i>= up; i--)
                    ans.push_back(matrix[i][left]);
                left ++;
            }
            
            
            direction = (direction + 1) % 4;
        }
        
        return ans;
    }
};