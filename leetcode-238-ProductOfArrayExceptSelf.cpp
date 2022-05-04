/**     https://leetcode.com/problems/product-of-array-except-self/

Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 

Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)
 * 
 */


/**
    Runtime: 25 ms
    Memory Usage: 24 MB
 */
class Solution {
public:
    
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        
        vector<int> ans(size, 0);
        
        // an optimization: if has at least one ZERO, then things are much simpler:
        int place_of_zero = -1;
        int num_zero = 0;
        for(int i=0; i<size; ++i){
            if(nums[i] == 0){
                num_zero ++;
                if(num_zero >= 2) return ans; // everything in answer became zero
                place_of_zero = i;
            }
        }
        
        if(num_zero == 1){
            int prod = 1;
            for(int i = 0; i < place_of_zero; ++i){
                prod *= nums[i];
            }
            for(int i = place_of_zero + 1; i < size; ++i){
                prod *= nums[i];
            }
            ans[place_of_zero] = prod;
            return ans;
        }
        
        // after this loop, ans[i] stores products from ans[0] ~ ans[i-1]
        ans[0] = 1;
        for(int i = 1; i < size; ++i){            
            ans[i] = ans[i-1] * nums[i - 1];
        }
        
        ans[size - 1] = ans[size - 1];
        int suffix = nums[size - 1];
        for(int i = size - 2; i >= 0; --i){
            // suffix: product from the last one to nums[i+1]
            // ans[i]: product form the first one to nums[i - 1]
            ans[i] = ans[i] * suffix;
            // ans[i]: real answer[i]
            suffix = suffix * nums[i];
        }
        
        return ans;
    }    
};
