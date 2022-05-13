/*      https://leetcode.com/problems/max-points-on-a-line/

*/

class Solution {
    
public:
    int maxPoints(vector<vector<int>>& points) {
        int max = 0;
        for(auto itr = points.begin(); itr != points.end(); itr++){
            unordered_map<int, unordered_map<int, int>> slopes;
            for(auto itr1 = points.begin(); itr1!=points.end(); itr1++){
                if(itr1 == itr) continue;
                int dx = (*itr1)[0] - (*itr)[0];
                int dy = (*itr1)[1] - (*itr)[1];
                int gcdxy = __gcd(dx, dy);
                dx /= gcdxy;
                dy /= gcdxy;
                slopes[dx][dy] +=1;
            }
            
            for(auto itr1: slopes){
                for(auto itr2: itr1.second){
                    if(max < itr2.second) 
                        max = itr2.second;   
                }
            }
        }
        
        return max + 1;
            
        
    }
};