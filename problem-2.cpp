// https://leetcode.com/problems/burst-balloons/description/

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

class Solution {
    public:
        int maxCoins(vector<int>& nums) {
            int n = nums.size();
            vector<vector<int>> dp(n, vector<int>(n,0));
            for(int le=1; le<=n; le++){
                
                for(int i=0; i<= n-le; i++){
                    int j=i+le-1;
                    int maxVal=0;
                    for(int k=i; k<=j; k++){
                        //kth balloon in the end
                        //left
                        int left = 0;
                        if(k != i){
                            left = dp[i][k-1];
                        }
                        //right
                        int right =0;
                        if(k != j){
                            right = dp[k+1][j];
                        }
                        //before
                        int bef = 1;
                        if(i != 0){
                            bef = nums[i-1];
                        }
                        //after
                        int aft = 1;
                        if(j != n-1){
                            aft = nums[j+1];
                        }
    
                        // left + before*kth*after + right
                        int curr = left + bef*nums[k]*aft + right;
                        maxVal = max(maxVal, curr);
                    }
                    dp[i][j] = maxVal;
                }
                
            }
            return dp[0][n-1];
        }
    };