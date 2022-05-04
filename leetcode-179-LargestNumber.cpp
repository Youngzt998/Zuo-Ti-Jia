
/**     https://leetcode.com/problems/largest-number/
    
 Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

 Since the result may be very large, so you need to return a string instead of an integer.

 Example 1:

 Input: nums = [10,2]
 Output: "210"
 Example 2:

 Input: nums = [3,30,34,5,9]
 Output: "9534330"
  
 Constraints:

 1 <= nums.length <= 100
 0 <= nums[i] <= 109
 
 */

/**
 Runtime: 4 ms
 Memory Usage: 11.7 MB
 */

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), myLess);
        
        if(nums[0] == 0) return to_string(0);
        
        string ans = "";
        for(auto itr: nums){
            ans = ans + to_string(itr);
        }
        
        return ans;
    }
    
    static bool string_less(string a, string b){
        if(a.size() < b.size()) return true;
        if(a.size() > b.size()) return false;
        
        for(int i = 0; i< a.size(); ++i){
            if(a[i] < b[i]) return true;
            if(a[i] > b[i]) return false;
        }
        
        return false;
    }
    
    static int getLen(long long int x){
        int cnt = 1;
        while(x>=10) {x /= 10; cnt ++;}
        return cnt;
    }
    
    static int ten_power_of(int n){
        int ans = 1;
        while(n --) ans *= 10;
        return ans;
    }
    
    static bool myLess(int a, int b){
        
        long long int la = a, lb = b;
        long long int ab = lb + la * ten_power_of(getLen(lb));
        long long int ba = la + lb * ten_power_of(getLen(la));
        
        return ab > ba;
    }
    
};
