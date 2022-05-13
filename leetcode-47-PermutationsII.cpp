/**     https://leetcode.com/problems/permutations-ii/
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 

Constraints:

1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/


class Solution {
    vector<vector<int>> ans;
    // unordered_set<int> removed;
    vector<int> cache;
    bool used[9] = {0};
    
    void computePermute(vector<int>& nums){       
        if(cache.size() == nums.size()){
            ans.push_back(cache);
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i){
            if(i != 0 && nums[i]==nums[i-1] && !used[i-1]) 
                continue;

            if(used[i]) continue;

            used[i] = true;
            cache.push_back(nums[i]);  
            computePermute(nums);
            cache.pop_back();
            used[i] = false;
        }  
    }
    
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        computePermute(nums);
        return ans;
    }
    
};