
/** https://leetcode.com/problems/4sum-ii/

Given four integer arrays nums1, nums2, nums3, and nums4 all of length n, return the number of tuples (i, j, k, l) such that:

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
 

Example 1:

Input: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
Output: 2
Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> nums1[0] + nums2[0] + nums3[0] + nums4[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> nums1[1] + nums2[1] + nums3[0] + nums4[0] = 2 + (-1) + (-1) + 0 = 0
Example 2:

Input: nums1 = [0], nums2 = [0], nums3 = [0], nums4 = [0]
Output: 1
 

Constraints:

n == nums1.length
n == nums2.length
n == nums3.length
n == nums4.length
1 <= n <= 200
-228 <= nums1[i], nums2[i], nums3[i], nums4[i] <= 228

*/



/**
    Runtime: 360 ms
    Memory Usage: 27.8 MB
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> left, right;
        
        for(auto i: nums1)
            for(auto j: nums2){
                // if(left.find(i+j)==left.end()) left[i+j] = 1;
                // else 
                    left[i+j] += 1;
            }
                
                
        for(auto k: nums3)
            for(auto l: nums4){
                // if(right.find(-k-l)==right.end()) right[-k-l] = 1;
                // else 
                    right[-k-l] +=1;
            }

        int cnt = 0;
        for(unordered_map<int, int>::iterator itr = left.begin(); itr!=left.end(); ++ itr){
            int val = itr->first, num = itr->second;
            // if(right.find(val) != right.end()) 
                cnt += num * right[val];
        }
        
        return cnt;
    }
};